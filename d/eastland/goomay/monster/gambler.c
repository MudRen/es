
#include "mudlib.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(5);
        set_name( "gambler", "�Ĺ�" );
        set_short( "�Ĺ�");
        set("unit","λ");
        set_long(
@C_LONG
�㿴��һ������ĺ��ӣ���ԼĪ����ʮ���꣬���ǿ�����ȴ���ϣ�Ӫ������
�����ϻ�����˯�߲���ĺۼ����˿�����ȫ���ע�غ�һ���˴���ضģ���
��û��ע�⵽��Ĵ��ڡ�
C_LONG
);
        set("alignment",-450);
        set("wealth/silver",15);
        set_perm_stat("str",12);
        set_perm_stat("dex",10);
        set_perm_stat("kar",9); 
        set_natural_weapon(5,5,11);
        set ("natural_armor_class", 25);
        set_skill("parry",65);
        set("natural_defense_bonus",5);
        set ("gender", "male");
        set ("race", "halfling");
#include <replace_mob.h>
}
