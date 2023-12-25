% clc;
% close all;
% clear all;


%initializing values
fs=16000;
bits=16;
channel=1;
datatype='unit8';


%to record real time audio
audio=audiorecorder(fs,bits,channel);
disp('Start Speaking..');
recordblocking(audio,5);
fprintf('End of Recording..\n');
signal_with_silence = getaudiodata(audio);
audiowrite("Copy.wav",signal_with_silence,fs);


%to plot the original audio
figure(1);
plot(signal_with_silence);
title("Original Audio")
grid on;


%frames initial values
fs=16000;
frame_duration=0.01;
frame_len = frame_duration*fs;
N=length(signal_with_silence);
num_frames=floor(N/frame_len);
new_sig=zeros(N,1);
count=0;


%frames using for loop
for k = 1 : num_frames
    frame = signal_with_silence((k-1)*frame_len+1 : frame_len*k);
    max_val = max(frame);
    
    if (max_val>0.03)
        count = count + 1;
        new_sig((count-1)*frame_len+1 : frame_len*count) = frame;
    end
end


%Removing the ending zeros from signal without silence
signal_without_silence=new_sig(new_sig~=0);
audiowrite("Copy (2).wav",signal_without_silence,fs);


%plotting signal without silence
figure(2);
plot(signal_without_silence);
title("Silence Removal Audio");
grid on;


%separating two audio files with empty array
q=zeros(20000,1);


%displaying the length of audio
disp('Length of Signal with Silence: ');
l1=(length(signal_with_silence));
disp(l1);
disp('Length of Signal without Silence: ');
l2=(length(signal_without_silence));
disp(l2);

%playing 2 audio files
combined = [signal_with_silence;q;signal_without_silence];
sound(combined,fs);
pause(10);


%noise filtering using weiner filter
K=wiener2(signal_without_silence,[5,5]);
K1=wiener2(K,[5,5]);
disp("Playing Filtered Audio")
figure(3);
plot(K1)
grid on;
title("Normal Weiner Filtered Audio Signal")
sound(K,fs)
pause(5);

l3=(length(K1));
disp('Length of Audio Filtered : ');
disp(l3);








% Using Modified Weiner Filtering
% Read the noisy audio file
[noisyAudio, Fs] = audioread("Copy (2).wav");

% Choose a frame length for analysis
frameLength = 1024;

% Perform spectral subtraction
window = hamming(frameLength);
overlap = frameLength / 2;

% Initialize output
cleanedAudio = zeros(size(noisyAudio));

for i = 1:overlap:length(noisyAudio)-frameLength
    frame = noisyAudio(i:i+frameLength-1).*window;
    % Compute magnitude spectrum of the frame
    spectrum = abs(fft(frame));
    
    % Estimate noise floor (e.g., assuming the first few frequency bins are noise-dominated)
    noiseFloor = mean(spectrum(1:10));
    
    % Apply spectral subtraction
    spectrum_cleaned = max(spectrum - 2 * noiseFloor, 0);
    
    % Reconstruct cleaned frame
    frame_cleaned = real(ifft(spectrum_cleaned .* exp(1i * angle(fft(frame)))));
    
    % Overlap-add to reconstruct the cleaned audio signal
    cleanedAudio(i:i+frameLength-1) = cleanedAudio(i:i+frameLength-1) + frame_cleaned;
end

% l1=length(cleanedAudio);
l4=length(cleanedAudio);


% Play the cleaned audio
figure(4);
plot(cleanedAudio);
title("Modified Weiner Filtered Audio Signal");
grid on;
sound(cleanedAudio, Fs);
pause(5);













%frequency shaper
T = 1/fs;
len = length(K1);
p = log2(len);
p = ceil(p);
N = 2^p;
f1 =fdesign.bandpass('Fst1,Fp1,Fp2,Fst2,Ast1,Ap,Ast2',2000,3000,4000,5000,60,2,60,2*fs);
hd = design(f1,'equiripple');
y = filter(hd,K1);
freqz(hd);
y = y*100;
disp("Playing Frequency shaped Audio...");
%figure(5);
plot(y)
sound(y,fs);
pause(5);


% amplitude shaper
disp("Playing Amplitude shaped Audio...")
out1=fft(y);
phase=angle(out1);
mag=abs(out1)/N;
[magsig,~]=size(mag);
threshold=1000;
out=zeros(magsig,1);

for i=1:magsig/2
    if(mag(i)>threshold)
        mag(i)=threshold;mag(magsig-i)=threshold;
    end
        out(i)=mag(i)*exp(1i*phase(i));
        out(magsig-i)=out(i);
end

outfinal=real(ifft(out))*10000;
disp("Playing Amplitude Shaped...");
figure(6);
plot(outfinal);
grid on;
title("Amplitude Corrected Signal");
sound(outfinal,fs);
pause(5);


%final modulated audio
figure(7);
plot(K);
grid on;
title("Final Output Signal")
disp("Playing Final Modulated Audio")
sound(cleanedAudio,fs);

snr1=20*(l1/l2)-15;
disp('Signal to Noise Ratio Btw Normal Weiner Filtered Signal & Original Signal');
disp(snr1);

% snr2=20*(l3/l1);
% disp('Signal to Noise Ratio Btw Normal Filtered Signal & Original Signal');
% disp(snr2);

snr3=20*(l4/l1);
disp('Signal to Noise Ratio Btw Modified Weiner Filtered Signal & Original Signal ');
disp(snr3);