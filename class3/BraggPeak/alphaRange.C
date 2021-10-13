{
	TTree *test = new TTree("","");
	test->ReadFile("BraggPeak.out","track:radius");
	test->Draw("track");
}
