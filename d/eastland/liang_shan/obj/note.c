#include "../takeda.h"

inherit OBJECT;

void create()
{
       set_name("cook note","��ʦ�ʼ�");
       add("id",({"note"}) );
       set_short("��ʦ�ʼ�");
	   set_long(
           "����һ���е㷢�Ƶıʼǣ���������ʦ������ĵ�...\n"
	);
	
	set( "unit", "��" );
	set( "value", ({ 10, "silver" }) );
}
