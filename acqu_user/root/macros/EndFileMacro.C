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
  //Get name of physics class
  //  strcpy(physname, gUAN->GetPhysics()->GetName());
  //Build histograms filename from physics and datafile
  //  sprintf(savename, "/scratch/roddym/%s.out.root", filename);
  //  sprintf(savename, "~/Documents/TagEff/%s.out.root", filename);
  sprintf(savename, "/w/work14/roddym/TaggEff/%s.out.root", filename);
  //sprintf(savename, "home/roddym/Documents/acqu/acqu_user/%s.out.root", filename);  // Use for creating new, initial, ladder files.

  //Save histograms
  gUAN->SaveAll(savename);
  gUAN->ZeroAll();
  printf("All histograms saved to %s and zero'ed\n", savename);
  //printf("All histograms saved to %s\n", savename);
}
