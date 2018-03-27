/*    Wezel<TYP_DANYCH>* Wpom = this->korzen, *Wpom_kon;
    ostringstream ss;
    string Drzewo;
    int pom = 1;
    int pom2 = 0;

    if(Wpom != NULL)
    {
        ss << Wpom->wartosc;
        Drzewo += ss.str() + "\n";
        ss.clear();
        ss.str("");

    do
    {
        while(Wpom->lewy != NULL)
        {
            pom += 1;
            Wpom = Wpom->lewy;

            for(int i = 1;i < pom; i++)
                    pom2 = Drzewo.find("\n", pom2+1);


            if(Drzewo.find("\n", pom2+1) == string::npos)
            {
                ss << Wpom->wartosc;
                Drzewo.insert(pom2+1, ss.str() + "\n");
                ss.clear();
                ss.str("");
            }else
            {
                ss << Wpom->wartosc;
                Drzewo.insert(Drzewo.find("\n", pom2+1), " , " + ss.str());
                ss.clear();
                ss.str("");
            }

            pom2 = 0;

        }

        if(Wpom->prawy != NULL)
        {
            pom += 1;

            for(int i = 1;i < pom; i++)
                    pom2 = Drzewo.find("\n", pom2+1);


            if(Drzewo.find("\n", pom2+1) == string::npos)
            {
                ss << Wpom->prawy->wartosc;
                Drzewo.insert(pom2+1, ss.str() + "\n");
                ss.clear();
                ss.str("");
            }else
            {
                ss << Wpom->prawy->wartosc;
                Drzewo.insert(Drzewo.find("\n", pom2+1), " , " + ss.str());
                ss.clear();
                ss.str("");
            }

            pom -= 1;
        }

        while(Wpom->rodzic != NULL)
        {
            if(Wpom == Wpom->rodzic->prawy)
            {
                Wpom = Wpom->rodzic;
                pom -= 1;
            }

            Wpom_kon = Wpom;

            if(Wpom->rodzic != NULL)
            {
                Wpom = Wpom->rodzic;
                pom -= 1;
            }else break;


            if(Wpom->prawy != NULL)
            {
                pom += 1;
                Wpom = Wpom->prawy;

                if(Wpom_kon == Wpom) break;

                for(int i = 0;i < pom; i++)
                    pom2 = Drzewo.find("\n", pom2+1);

                ss << Wpom->wartosc;
                Drzewo.insert(pom2, " " + ss.str());
                ss.clear();
                ss.str("");
                pom2 = 0;

                break;
            }
        }
    }while(Wpom_kon != Wpom);

    pom = 0;
    pom2 = 0;

    do
    {
        pom = Drzewo.find("\n", pom+1);
        pom2 += 1;

    }while(pom != string::npos);

    pom = 0;

    for(int i = pom2-1; i > 0; i--)
    {


        pom2 = -1;
        for(int j = 0; j < i-1; j++)
        {
            pom2 = Drzewo.find("\n", pom2 + 1);

        }
        for(int k = 0; k < pom; k++)
            Drzewo.insert(pom2+1," ");

        pom = 2*pom + 1;
    }
*/

//    cout<<Drzewo<<endl;

    //}
