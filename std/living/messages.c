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
    if( str == "" ) str = "$N("+capitalize((string)this_object()->query("name"))+")���˹�����";
    ob = this_object()->query_temp("mounting");
    str = substr( str, "$N", this_object()->query("c_name") + (ob?
    	"����һ" + ob->query("unit") + ob->query("c_name"): "") );
    return set_color(str, color);
}

string query_c_mout(string dir)
{
    string str, color;
    object ob;

    str = (string)this_object()->getenv("C_MOUT");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N", "$D" }) );
    if( str == "" ) str = "$N("+capitalize((string)this_object()->query("name"))+")��$D���뿪��";
    ob = this_object()->query_temp("mounting");
    str = substr( str, "$N", this_object()->query("c_name") + (ob?
    	"����һ" + ob->query("unit") + ob->query("c_name"):"") );
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
    if( str == "" ) str = "��һ�������У�$N�����������ǰ��";
    str = substr( str, "$N", (string)this_object()->query("c_name") );
    return set_color(str, color);
}

string query_c_mmout()
{
    string str, color;

    str = (string)this_object()->getenv("C_MMOUT");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "һ��������ᣬ$N��ʧ�ڿ����С�";
    str = substr( str, "$N", (string)this_object()->query("c_name") );
    return set_color(str, color);
}

string query_c_mhome()
{
    string str, color;

    str = (string)this_object()->getenv("C_MHOME");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "һ��������ᣬ$N��ʧ�ڿ����С�";
    str = substr( str, "$N", (string)this_object()->query("c_name") );
    return set_color(str, color);
}

string query_c_mdest(object obj)
{
    string str, color;

    str = (string)this_object()->getenv("C_MDEST");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N", "$O" }) );
    if( str == "" ) str = "$N����һ�����磬��$O��Ϊ�ҽ���";
    str = substr( str, "$N", (string)this_object()->query("c_name") );
    if (obj == 0) return str;
    if( obj->query("short") )
        str = substr( str, "$O", (string)obj->query("short") );
    else
        str = substr( str, "$O", "ĳ������" );
    return set_color(str, color);
}

string query_c_mclone(object obj)
{
    string str, color;

	str = (string)this_object()->getenv("C_MCLONE");
	color = (string)this_object()->getenv("ENV_COLOR");
	str = validate( str, ({ "$N", "$O" }) );
	if( str == "" ) str = "ֻ��$N�����ڿ���һ����$O�ͳ����������ǰ��";
	str = substr( str, "$N", (string)this_object()->query("c_name") );
       if (obj == 0) return str;
	if( obj->query("short") )
		str = substr( str, "$O", (string)obj->query("short") );
	else str = substr( str, "$O", "ĳ������" );
	return set_color(str, color);
}

string query_c_mvis()
{
    string str, color;

    str = (string)this_object()->getenv("C_MVIS");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "�㿴��$N����Ӱ��͸����������ɼ���";
    str = substr( str, "$N", (string)this_object()->query("c_name") );
    return set_color(str, color);
}

string query_c_minvis()
{
    string str, color;

    str = (string)this_object()->getenv("C_MINVIS");
    color = (string)this_object()->getenv("ENV_COLOR");
    str = validate( str, ({ "$N" }) );
    if( str == "" ) str = "$N��Ӱ�ӿ�ʼ�䵭�����������ȫ��ʧ�ˡ�";
    str = substr( str, "$N", (string)this_object()->query("c_name") );
    return set_color(str, color);
}
