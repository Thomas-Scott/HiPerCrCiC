#include<iostream>

class Crawler{
	static string search = "\"http://worldnews.msnbc.msn.com/";
	static vector<string> queue;
	static vector<string> done_queue;
	static vector<string> content;
	string download(string str);
	void check(string str);
}sharp;
string Crawler::download(string str)
{

}
void Crawler::check(string str)
{
	int i = 0;
	while(true)
	{
		boolean done = false;
		int startpos = str.find(search,i)+1;
		if(startpos <= 0)
			break;
		int endpos = str.find("\"",startpos);
		string url = str.substr(startpos, (endpos-startpos));
		i = endpos;
		for(int s = 0; s < this->queue.size(); s++)
		{
			if(this->queue[s].equals(url))
			{
				done = true;
				break;
			}
		}
		if(done != true)
		{
			for(int b = 0; b < donequeue.size(); b++)
			{
				if(queue.at(b) == url)
				{
					done = true;
					break;
				}
			}
	}	
}
int main()
{
	string starturl = "http://worldnews.msnbc.msn.com/";
	string startpage = sharp.download(starturl);
	sharp.done_queue.push_back(starturl);
	sharp.queue.push_back(starturl);
	sharp.check(startpage);
	sharp.queue.remove(0,1);
	sharp.content.push_back(startpage);
	int limit = 0;
	while(limit < 2)
	{
		string url = sharp.queue[0];
		string page = sharp.download(url);
		sharp.check(page);
		FILE WRITING
		sharp.content.push_back(page);
		sharp.done_queue.push_back(sharp.queue[0]);
		sharp.queue.erase(0,1);
		limit++;
	}
}
