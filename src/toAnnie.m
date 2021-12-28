% annie - Neural Network Library for C++
% http://annie.sourceforge.net/
% asimshankar@users.sourceforge.net
%
% Last Modified On :
% Author(s):
%	Asim Shankar
%
% This file contains Matlab commands to save the weights
% and biases of a two-layer feed-forward network in Matlab
% into text files.
%
% Use the command-line utility provided with annie's
% Matlab-Extensions Pack (which is probably where you
% found this file) to get the same network in a format
% that will be understood by the annie library and 
% make possible the use of the network in C++ applications.
%
% The weights between the input layer and hidden layer
% are exported to a file - "InputWeights.txt"
% 
% The weights between the hidden layer and output layer
% are exported to - "HiddenWeights.txt"
%
% The biases of the hidden neurons are exported to
% - "HiddenBiases.txt"
%
% The biases of the output neurons are exported to
% - "OutputBiases.txt"
%
% To change these filenames, just replace the 
% occurrence of these names with the name of the file
% you want int the code below.

iw = net.IW{1};
save 'c:\InputWeights.txt' iw -ASCII;
lw = net.LW{2,1};
save 'c:\HiddenWeights.txt' lw -ASCII;
b = net.b{1};
save 'c:\HiddenBiases.txt' b -ASCII;
b = net.b{2};
save 'c:\OutputBiases.txt' b -ASCII;