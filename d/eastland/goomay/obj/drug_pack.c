#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("pack of herbs","ҩ��");
        add( "id" , ({ "pack" }) );
        set_short("a pack of herbs" , "ҩ��");
        set_long("This is a pack of herbs .\n" ,
		 "����һ�����������ҩ�ĵ�ֽ������������Ũ����ҩ���㡣\n");
        set("unit","��");
        set("weight", 10);
        set("value", ({20, "silver"}) );
}
