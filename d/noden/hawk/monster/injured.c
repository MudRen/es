#include "../hawk.h"
inherit MONSTER;
void create()
{
        ::create();
        set_level(5);
        set_name( "Injured hawkman soldier","���˵�������ʿ��" );
        add("id",({"injured","hawkman","soldier"}) );
        set_short( "���˵�������ʿ��" );
        set_long(@LONG
һ��������Ѫ��������ʿ�������Ͽ�������ʹ������ӣ�������Ѫ����
���������Ŀ����㣬���΢�˫��΢΢�ķ�����
LONG
        );
        set( "alignment", -400 );
        set( "gender","male" );
        set( "race","hawkman" );
        set( "chat_chance", 5 );
        set( "chat_output",({
"ʿ��ʹ����ڵ�������:..��..........�ҾͿ�Ҫ����\n",
"ʿ��������...:��˵.... ��Ĺ����(pray)����ȥ������Ϳ��Եõ���Ϣ..\n",
"ʿ�������̾��һ����.... : Ϊʲ��Ҫ��ս����? \n"
        }));
        set( "natural_weapon_class1", 10 );
        set( "natural_min_damage1", 4 );
        set( "natural_max_damage1", 9 );
        set_perm_stat( "str", 7 );
        set_perm_stat( "dex", 2 );
        set_perm_stat( "kar", 10 );
        set_perm_stat( "int", 3 );
        set_skill( "dodge", 10 );
                     set("hit_points",90);
}
