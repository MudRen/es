
#include "../asterism.h"
inherit WEAPON;

void create()
{
        set_name("sad dagger", "����ذ��");
        add ("id",({ "dagger" }) );
        set_short("����ذ��");
        set_long(
            "����һ�Ѻܷ�����ذ��,������һЩ�������������,�ƺ��ǹ��ϵ�\n"
            "����������,�����㲢�޷�ȷ��.\n"
        );
        set( "unit", "��");
        set( "weapon_class", 20 );
        set( "type", "dagger" );
        set( "min_damage", 13);
        set( "max_damage", 21 );
        set( "weight", 110 );
        set( "value", ({ 820, "silver" }) );
}

//void init()
//{
//   add_action("to_read","read");
//}

//int to_read(string str)
//{
//    if (!str||str!="writing") return 0;
//    else { 
//       return 1;
//      }
//}
