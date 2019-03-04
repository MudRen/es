#include "../ruin.h"

inherit OBJECT;

void create()
{
	seteuid( getuid() );
	set_name("a pile of bones", "һ�ѿݹ�");
	set_short("ɢ���ڵ����ϵ�һ�ѿݹ�");
	set_long(
	   "��ѿݹ�, �����ƺ����˵ĹǺ�, ɢ�����ﲻ֪�Ѿ����˶��ٵ����¡�\n");
	set("id", ({ "bones", "skeleton"}));
	set("unit", "��");
	set("weight", 50 );
	set("use_less", 1);
	set("value", ({ 0, "silver" }) );
	set("prevent_get", 1);
	set("prevent_get_c_msg","������Ϣ��! �������ߡ�\n");
	set("prevent_insert", 1);
	set("prevent_drop", 1);
}

void	init()
{
	add_action( "do_search", "search" );
}

int		do_search(string s)
{
	if (!s)	return 0;
    if ( s == "skeleton" || s == "bones" )
	{
		printf( "%s", "�������������Ǻ�ʱ, ��ͻȻ���ٵط绯Ϊһ��"
		"ϸɳ, ɢʧ춷��С�\n");
		this_object()->remove();
		return 1;
	}
}
