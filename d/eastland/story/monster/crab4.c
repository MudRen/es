#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(16);
       set_name( set_color("Crab","HIR"),set_color("С�з","HIR") );
       add("id",({"crab"}) );
       set_short( set_color("С�з","HIR") );
       set("unit","ֻ");
       set_long(set_color("
    
      ��        ��
     �� ��  �� ��
    ��\\�ء���/��    ��һֻȫ�����С�з������������������������
    ����    ��������   ������
     ����������


       \n","HIR"));
       set_perm_stat("str",25);
       set_natural_armor(75,0);
       set_natural_weapon(27,18,29);
       set_c_verbs(({"%s�����ľ�����%s����"}));
       set_c_limbs(({"����","ͷ��","��"}));
}

