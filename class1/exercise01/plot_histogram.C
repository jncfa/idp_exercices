#include <TROOT.h>
#include <TH1F.h>

#include <iostream>
#include <fstream>

#define MAX_BINS 1000000

int plot_histogram(){

	// Let's start by defining the histogram
	Int_t num_bins = 20;
	TH1F *histogram = new TH1F("h001","Uniformity test",num_bins,0.,1.);

	// And now open the file
	ifstream file("random_numbers.dat");

	// Fill the histogram with the values from the file
	Float_t a_number;
	Int_t entries = 0;
	while (file >> a_number){
		histogram->Fill(a_number); 
		entries++;
	}
	cout << "Number of randoms in the file: " << entries << endl;

	// Let's normalise each bin to the number of entries
	double variance = 0;
	double mean = 0;
	for(int i=1; i<=num_bins; i++){
		double frequency = histogram->GetBinContent(i) / entries;
		variance += pow(frequency-1./num_bins,2);
		mean += frequency / num_bins;
		histogram->SetBinContent(i,frequency);
	}
	// We must set the maximum and the minimum of the histogram
	histogram->SetMinimum(0); histogram->SetMaximum(0.1);
	// Finally, let's plot the histogram
	histogram->SetStats(kFALSE);
	histogram->Draw();
	cout << "Mean of the histogram: " << mean << endl;
	std::cout << "Standard deviation of the distribution: "
              << sqrt(variance/num_bins)
              << " (" << sqrt(variance/num_bins)/mean *100. << "%)"
              << std::endl;
    // and draw a line at the mean
    TLine *meanL = new TLine(0.,mean,1.,mean);
    meanL->SetLineStyle(2); meanL->SetLineColor(kRed);
    meanL->Draw("same");
    
	file.close();
	
	return 0;
}
