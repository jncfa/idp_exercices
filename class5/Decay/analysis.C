{
	TTree *test = new TTree("","");
	test->ReadFile("Decay_Ne24.out","energy:time");
	test->Draw("time");
}
