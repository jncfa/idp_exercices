{
	TTree *shieldingData = new TTree("shieldingData","");
	shieldingData->ReadFile("Shielding_Pb.out","x:y:z:kinE");
    shieldingData->Draw("z:y","z<30. && kinE == 1","");
    shieldingData->SetLogz();
    shieldingData->SaveAs("BraggPeak.pdf");
}
