#include "../iigima.h"

inherit MONSTER ;
void create ()
{
        ::create();
        set_level(5);
        set_name("Young man Pan","�����˶�" );
        add ("id", ({"drow", "pan","man" }) );
        set_short( "�����˶�" );
        set("unit","λ");
        set_long(
@C_LONG
��λ�¸ҵ����������ΪŮ���ѵٵ�(Teeder)�����������̳�����
��������������������һ�ѷ����Ķ̽�������Ҫ�ȳ��Լ��İ��ˡ�
C_LONG
        );
        set ("gender", "male");
        set( "no_attack", 1 );
     set( "chat_chance", 16 );
        set( "chat_output", ({
               "�˶�������˵��: ��һ��Ҫ�ȳ��ٵ�!\n",
               "�˶�������С����������ŵض岽��.....\n"
                       }));
        set( "inquiry", ([
         "teeder" : ({ "�ٵ����ҵ�Ů������~�Ǹ��ɶ����پ�Ȼ���ҵĵٵ�ץȥ���..��\n"
                    })
                          ]) );
   wield_weapon("/d/deathland/weapon/dagger01");
}
