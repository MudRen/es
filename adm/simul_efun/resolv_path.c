/*
// Original Basis resolv_path.c was from Huthar
// This version totally rewritten by Zak, 921201.
// Zak, 930105:	changed so will resolv even if user unknown...
// Added cur = "cwd", idea from Pallando.
*/

//
// Usage: resolv_path( cur, new )
//	cur -	current dir, or "cwd"
//	new -	dest dir, resolvs .., ., "here", and ~
//

varargs string resolv_path(string cur, string newa) {

    string *path, *tmp;
    int pos, i;

    if (cur == "cwd")
	if (this_player())		// idea from Pallando
	    cur = (string) this_player()->query("cwd");
	else
	    cur = "";			// to fall thru below
    if (!cur || cur == "")
	cur = "/";
    if (!newa || newa == "" || newa == ".")
	return cur;
    if(newa == "here" || newa == "env")
	if (environment(this_player()))
	    return file_name(environment(this_player())) + ".c";
	else
	    return "NONAME.c";
    if (newa == "/")
	return newa;

    if (cur == "/" || newa[0] == '/')
	path = ({ });
    else
	path = explode(cur, "/");
    tmp = explode(newa, "/");
    if(!tmp || !sizeof(tmp))
	return "/";
    if (tmp[0][0] == '~')
    {
  	string home, hdir;
 
	if (tmp[0] == "~")
	    home = (string)this_player()->query("name");
	else
	    home = extract(tmp[0], 1);
	if (home)
	{
	    string hpath;
	    hpath = user_path(home);
 
	    hdir = (string)this_player()->query("home_dir");
	    if(hdir)  hpath = hdir;

	    if(hpath[strlen(hpath)-1] != '/')  hpath += "/";
 
#if 0
			// new method
	    if (file_size(hpath) != -2)
		write("Unknown user: "+home+"\n");
#endif

	    path = explode(hpath, "/");
	}
	tmp -= ({ tmp[0] });
    }

    pos = sizeof(path);
    for(i = 0; i < sizeof(tmp); i++)
    {
	if (!tmp[i] || tmp[i] == "" || tmp[i] == ".")
	    continue;
	if (tmp[i] == "..")
	{
	    pos--;
	    if (pos<0)
		pos = 0;
	    continue;
	}
	if (pos >= sizeof(path))
	    path += ({ tmp[i] });
	else
	    path[pos] = tmp[i];
	pos++;
    }
    return ( "/" + implode(path[0..pos - 1], "/" ));
} /* resolv_path */
