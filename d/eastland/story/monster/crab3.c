#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(4);
       set_name( set_color("Crab","HIG"), set_color("С�з","HIG") );
       add("id",({"crab"}) );
       set_short( set_color("С�з","HIG") );
       set("unit","ֻ");
       set_long(set_color("
    
      ��        ��
     �� ��  �� ��
    ��\\�ء���/��    һֻȫ����ɫ��С�з�������������ƣ�СС���۾�
    ����    �������� ��ģ���ɰ����ˡ�  
     ����������

       
       \n","HIG"));
       set_natural_armor(20,0);
       set_natural_weapon(5,3,6);
       set_c_verbs(({"%s����������%s����"}));
       set_c_limbs(({"����","ͷ��","��"}));
}

