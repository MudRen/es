#include "../zeus.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(11);
       set_name( "dog", "����Ȯ" );
       set_short( "dog","����Ȯ");
       set("unit","ֻ");
       set_long(@LONG
һֻ���������ŵ��ҹ���Сܰ
LONG
);
       set_perm_stat("dex", 20);
       set_perm_stat("str",18);
       set_perm_stat("kar",15);
       set_natural_weapon(20,10,20);
       set_natural_armor(50, 15);
       set_c_verbs(({"%s����������%sҧȥ"}));
       set_c_limbs(({"����","����","�Ų�","ͷ��"}));
       set("killer",1);
       set("chat_chance",20 );
       set("att_chat_output",({
                "����Ȯ��ͣ�Ŀ��:������������������\n"
                }));
                }
void die()
{
     tell_room(environment(this_object()),
@DIE

���ϴ�ͻȻ��æ�����˳����е�:ס�֣�ס�֣���������Сܰ�㾹Ȼ�����۸�
��������ӣ����ĺ�����һ���������������.
���ϴ��Ȼ��ת����ȥ��ֻ����һ�仰:����Ҽ�ס......................

DIE
,this_object());
    ::die(1);
    }   

