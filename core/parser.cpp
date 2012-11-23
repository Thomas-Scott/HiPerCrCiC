	fstream f(fileName, fstream::in );
  	string content;
  	getline( f, content, '\0');
	f.close();
	string search = "http";
	int contentLocation = 0;
	while(true)
	{
		boolean duplicate = false;
		int startpos = content.find(search,contentLocation);
		if(startpos <= 0)
			break;
		int endpos = content.find("\"",startpos);
		string url = content.substr(startpos, (endpos-startpos));
		contentLocation = endpos;
		for(int s = 0; s < queue.size(); s++)
		{
			if(queue[s] == (url))
			{
				duplicate = true;
				break;
			}
		}
		if(!duplicate)
		{
			for(int b = 0; b < doneQueue.size(); b++)
			{
				if(queue.at(b) == url)
				{
					duplicate = true;
					break;
				}
			}
		}
		if(!duplicate)
		{
			char * URL;
			int length = url.size();
			URL = new char[length];
			for(int i = 0; i < length; i++)
				URL[i] = url[i];
			URL[length] = '\0';
			if(notBlacklisted(URL) && allowed(URL))
				queue.push_back(URL);
		}	
	}