{
	TTree *test = new TTree("","");
	test->ReadFile("csda_air.out","csda");
	test->Draw("csda");
}
