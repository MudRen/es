#include "../oldcat.h"        
        
inherit MONSTER;

void create ()
{               
       object ob;
       ::create();
       set_level(18);
       set_name( "unicorn","������");
       set_short( "������");
       set("unit","ֻ");
       set_long(
       "����һֻ���ޣ������������Ƶ���������һֻ���صĽǣ��벻Ҫ�˺�������Ϊ�д�˵\n�������˺��������콫�ή������ˡ�\n");
       set_perm_stat("dex", 30);
       set("natural_weapon_class1",57);
       set("natural_armor_class", 90);
       set_perm_stat("str",25);
       set_perm_stat("kar",25);
       set_perm_stat("int",20);
       set_perm_stat("pie",20);
       set_skill("dodge",100);
       set("natural_defense_bonus",50);
       set("alignment",2000);
       set("max_hp",1000);
       set("hit_points",1000);
       set("natural_min_damage1",20);
       set("natural_max_damage1",34);
       set_c_verbs(({"%s������������%s��ȥ","%s�����Ľ���%s��ȥ"}));
       set_c_limbs(({"����","β��","�Ų�","ͷ��"}));
}
