#include "../dgnisld.h"

inherit OBJECT;

void create()
{
        set_name( "Dragon ball", "����" );
        add( "id", ({ "ball" , "dragon ball" ,}) );
        set_short( "Dragon ball", "����");
        set_long(
            "This is the Dragon ball in old legend. \n",
            "����Ǵ�˵�е����顣��ɢ����΢���Ĺ�â������һ��ҹ���顣\n"
            "�������������Ŀ��Կ�������С�ǡ�\n");
        set("weight", 5 );
        set("prevent_insert",1);
        set("value", ({ 1 , "gold" }) );
        set("dgnball", 1);
        set("unit", "��");
}           
