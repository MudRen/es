#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(5);
       set_name( "crab", "С�з" );
       add("id",({"crab"}) );
       set_short( "С�з" );
       set("unit","ֻ");
       set_long("
    
      ��        ��
     �� ��  �� ��
    ��\\�ء���/��    ��һֻȫ���׵�С�з�����������ڶ�������æ�ò������
    ����    ��������   �ƺ���������Ĵ��ڡ�
     ����������

       
       \n");
       set_natural_armor(25,0);
       set_natural_weapon(7,4,8);
       set_c_verbs(({"%s����������%s����"}));
       set_c_limbs(({"����","ͷ��","��"}));
}

