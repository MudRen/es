#include <mudlib.h>

inherit ARMOR;

void create()
{
	seteuid(getuid());
	set_name("unknow armor","δ֪����");
	set_short("δ֪����");
	set( "long","@@query_long");
	set( "weight","@@query_weight");
	set( "no_sale", 1);
	set( "c_skin_name","ëƤ");
	set( "extra_ids",({}));
}

string query_long()
{
	if ( (string) this_object()->query("c_skin_name") != "skin" )
		return "����һ" + (string) this_object()->query("unit") + "��" + (string)this_object()->query("c_skin_name") +"��Ƥ���ɵ�"
		 +(string)this_object()->query("add_name")+ "��\n";
	else
		return "����һ��δ��ɵķ��ߡ�\n";	
}
