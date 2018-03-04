% MATLAB/Octave script to plot graph for q14
MIN_X = 0;
MAX_X = 300;
MAX_X_DISPLAY = 10000;
MIN_Y = 0;
MAX_Y = 0.000005;

secondsPerStep = 10^(-9);

% Set up figure
disp("Plotting graph for q14...");
axis([MIN_X, MAX_X, MIN_Y, MAX_Y]);
hold on;
x = MIN_X:MAX_X_DISPLAY;

% Plot each curve
plot(x, log(x) .* secondsPerStep);
plot(x, x .* secondsPerStep);
plot(x, log(x) .* x .* secondsPerStep);
plot(x, power(x, 2) .* secondsPerStep);
plot(x, power(x, 3) .* secondsPerStep);
plot(x, power(2, x) .* secondsPerStep);

% Configure legend
h = legend("log n", "n", "n\log n", "n^2", "n^3", "2^n");
legend boxoff;
set(h, "fontsize", 14);

% Don't automatically exit after plotting
pause
