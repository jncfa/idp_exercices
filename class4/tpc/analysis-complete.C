{
	TTree *test = new TTree("test","");
	test->ReadFile("Shielding_Pb.out","x:y:z:kinE");
	//test->Draw("kinE");
	//test->Draw("kinE","kinE==1000");
	//test->Draw("sqrt(z**2+y**2)","kinE==1000 && sqrt(z**2+y**2)<0.001");
    	//test->Draw("z:y","sqrt(z**2+y**2)<10 && kinE<1000","contz");
	//test->Draw("atan(sqrt(z**2+y**2)/x)");
	//test->SetFillColor(kRed);
	//test->Draw("atan(sqrt(z**2+y**2)/x)","kinE<1000.","same");
	//test->SetFillColor(kBlue);
	//test->Draw("atan(sqrt(z**2+y**2)/x)","kinE==1000","same");
	//test->SetFillColor(0);
	//test->SetLineColor(kRed); test->SetLineWidth(3);
	test->Draw("kinE:atan(sqrt(z**2+y**2)/x)","kinE==1000.","prof");
	//test->GetXaxis()->SetTitle("Scattering angle (rad)");
}
