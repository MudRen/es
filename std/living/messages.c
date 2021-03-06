//#pragma save_binary

// This file contains the stuff for those funky movement messages you
// see when you move around... actually other people see them and not you.
// Be kind and admit that while you don't know who wrote this, that it did
// come from TMI.
// While you're at it, admit to a sneaking suspicion that Sulam may have
// been the author, although the concept probably goes back further than
// that.

string validate(string str, string *vars)
{
    string foo;
    int x;

    if( !str ) return "";
    for (x = 0; x < sizeof( vars ); x++)
	if( !( sscanf(str, "%s" + vars[x] + "%s", foo, foo) ) )
	    return "";
    return str;
}

string query_c_min()
{
    string str, color;
    object ob;

    str = (string)this_object()->getenv("C_MIN");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "$N("+capitalize((string)this_object()->query("name"))+")走了过来。";
    ob = this_object()->query_temp("mounting");
    str = substr( str, "$N", this_object()->query("c_name") + (ob?
    	"骑著一" + ob->query("unit") + ob->query("c_name"): "") );
    return set_color(str, color);
}

string query_c_mout(string dir)
{
    string str, color;
    object ob;

    str = (string)this_object()->getenv("C_MOUT");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N", "$D" }) );
    if( str == "" ) str = "$N("+capitalize((string)this_object()->query("name"))+")往$D边离开。";
    ob = this_object()->query_temp("mounting");
    str = substr( str, "$N", this_object()->query("c_name") + (ob?
    	"骑著一" + ob->query("unit") + ob->query("c_name"):"") );
    if (dir == "" || dir == 0) return str;
    str = substr( str, "$D", to_chinese(dir) );
    return set_color(str, color);
}

string query_c_mmin()
{
    string str, color;

    str = (string)this_object()->getenv("C_MMIN");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "在一阵烟雾中，$N出现在你的面前。";
    str = substr( str, "$N", (string)this_object()->query("c_name") );
    return set_color(str, color);
}

string query_c_mmout()
{
    string str, color;

    str = (string)this_object()->getenv("C_MMOUT");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "一阵烟雾过後，$N消失在空气中。";
    str = substr( str, "$N", (string)this_object()->query("c_name") );
    return set_color(str, color);
}

string query_c_mhome()
{
    string str, color;

    str = (string)this_object()->getenv("C_MHOME");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "一阵烟雾过後，$N消失在空气中。";
    str = substr( str, "$N", (string)this_object()->query("c_name") );
    return set_color(str, color);
}

string query_c_mdest(object obj)
{
    string str, color;

    str = (string)this_object()->getenv("C_MDEST");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N", "$O" }) );
    if( str == "" ) str = "$N召来一道闪电，把$O化为灰烬。";
    str = substr( str, "$N", (string)this_object()->query("c_name") );
    if (obj == 0) return str;
    if( obj->query("short") )
        str = substr( str, "$O", (string)obj->query("short") );
    else
        str = substr( str, "$O", "某样东西" );
    return set_color(str, color);
}

string query_c_mclone(object obj)
{
    string str, color;

	str = (string)this_object()->getenv("C_MCLONE");
	color = (string)this_object()->getenv("ENV_COLOR");
	str = validate( str, ({ "$N", "$O" }) );
	if( str == "" ) str = "只见$N用手在空中一画，$O就出现在你的面前。";
	str = substr( str, "$N", (string)this_object()->query("c_name") );
       if (obj == 0) return str;
	if( obj->query("short") )
		str = substr( str, "$O", (string)obj->query("short") );
	else str = substr( str, "$O", "某样东西" );
	return set_color(str, color);
}

string query_c_mvis()
{
    string str, color;

    str = (string)this_object()->getenv("C_MVIS");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "你看到$N的人影从透明变成清晰可见。";
    str = substr( str, "$N", (string)this_object()->query("c_name") );
    return set_color(str, color);
}

string query_c_minvis()
{
    string str, color;

    str = (string)this_object()->getenv("C_MINVIS");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "$N的影子开始变淡，最後终於完全消失了。";
    str = substr( str, "$N", (string)this_object()->query("c_name") );
    return set_color(str, color);
}
