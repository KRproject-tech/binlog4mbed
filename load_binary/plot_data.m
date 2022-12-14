clc
clear all
close all hidden

%% delete
delete( '*.asv')


%% initializing
initializing


%% file name
file_name = 'data.log';


%% load data

data = load_bin( file_name, 'int16');

time_m = data(:,1)/1000;        %% [ms] -> [s]
out = data(:,2:end)/100;        %% [c] -> [-]



%% plot

i_ax = 1;

h_fig(1) = figure( 1);
h_ax(i_ax) = axes( 'Parent', h_fig( 1));


plot( h_ax(i_ax), time_m, out, '.-')
xlabel( h_ax(i_ax), 'time [s]')
ylabel( h_ax(i_ax), 'data [-]')