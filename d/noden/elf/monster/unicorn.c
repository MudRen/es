#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(18);
       set_name( "unicorn","������");
        set_short( "������" );
       set("unit","ֻ");
        set_long(
       "����һֻ���ޣ������������Ƶ���������һֻ���صĽǣ���\n"
       "��Ҫ�˺�������Ϊ�д�˵�������˺��� �����콫�ή�������\n" );
       set_perm_stat("dex", 30);
       set("natural_weapon_class1",35);
       set("natural_armor_class", 80);
       set_perm_stat("str",20);
       set_perm_stat("kar",25);
       set_perm_stat("int",20);
       set_perm_stat("pie",20);
       set_skill("dodge",100);
       set("natural_defense_bonus",24);
       set("alignment",2000);
       set("max_hp",500);
       set("hit_points",500);
       set("natural_min_damage1",19);
       set("natural_max_damage1",35);
       set_c_verbs(({"%s������������%s��ȥ","%s�����Ľ���%s��ȥ"}));
       set_c_limbs(({"����","β��","�Ų�","ͷ��"}));
}
