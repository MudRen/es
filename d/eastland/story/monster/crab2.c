#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(6);
       set_name( set_color("Crab","HIY"),set_color("С�з","HIY") );
       add("id",({"crab"}) );
       set_short( set_color("С�з","HIY") );
       set("unit","ֻ");
       set_long(set_color("
    
      ��        ��
     �� ��  �� ��
    ��\\�ء���/��    ��һֻȫ���ɫ��С�з����֪�������ʲ�����ࡣ
    ����    ��������   ���������ڲ�ʳ��
     ����������

       
       \n","HIY"));
       set_natural_armor(30,0);
       set_natural_weapon(9,5,9);
       set_c_verbs(({"%s����������%s����"}));
       set_c_limbs(({"����","ͷ��","��"}));
}

