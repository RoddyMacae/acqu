void EndFileMacro()
{
  //Stuff to do at the end of a data file
  //Here all spectra are saved to disk
  Char_t filename[3072];
  Char_t physname[1024];
  Char_t savename[4096];
  Char_t* ptr;

  //Get name of file being analysed
  if(strlen(gUAN->GetFileName())) //Online, i.e. .dat files:
  {
    strcpy(filename, gUAN->GetFileName());
  }
  else //Offline, i.e. .rd0 files
  {
    strcpy(filename, gROOT->GetFile()->GetName());
    //Cut directory names
    ptr = strrchr(filename, '/');
    strcpy(filename, ptr+1);
  }
  printf("End-of-File macro executing after file %s\n", filename);
  //Cut file extension (.dat or .rd0)
  ptr = strrchr(filename, '.');
  *ptr = '\0';
  //Build histograms filename from physics and datafile
  sprintf(savename, "/scratch/roddym/tmp/%s.out.root", filename);
  //Save histograms
  gUAN->SaveAll(savename);
  //  gUAN->ZeroAll();  When Running on Farm, must be taken out as macro runs twice, deleting histograms and saving zero events (Due to problem in src code).
  //printf("All histograms saved to %s and zeroed\n", savename);
  //printf("All histograms saved to %s\n", savename);
}
