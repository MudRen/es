#include <mudlib.h>
inherit OBJECT;
void create()
{
	set_name("cage key","����Կ��");
	add("id",({"key"}));
	set_short("����Կ��");
	set_long("�����������������ӵ�Կ�ס�\n");
	set("to_lock","WANG");
	set("weight",4);
	set("value",({15,"silver"}));
}

