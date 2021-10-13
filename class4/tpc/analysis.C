{
	TTree *test = new TTree("","");
	test->ReadFile("Shielding_Pb.out","x:y:z:kinE");
	test->Draw("kinE");
    // try the following lines too
    //test->Draw("z:y","z<30.","colz");
    //test->Draw("z:y","z<30.","lego1");
}
