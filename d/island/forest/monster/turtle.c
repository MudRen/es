#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(15);
    set_name("Huge Turtle","�޹�");
    add("id",({"turtle"}) );
    set_short("�޹�");
    set_long(@LONG
����һֻ�޴���Ϻ��꣬����ĥ�۵Ĺ�Ǽ��������Ƶ�Ƥ����������ʾ�������߹�
�������Ƕ�����ƾã������ͻȻ�ĳ��֣����ƺ��Ե��е㾪�ȣ�����˴��ѵ�����
���������ðɣ�ǧ��Ҫ������Ŷ��һ�����������������ɲ��Ǻ������û�µ�Ŷ��
LONG
            );
    set("unit","ֻ");
    set("alignment",-1500);
    set("weight",2000);
    set("likefish",1);
    set_perm_stat("str",25);
    set("hit_points",1000);
    set("max_hp",1000);
    set_natural_weapon(40,20,30);
    set_natural_armor(50,40);
    set("unbleed",1);
    set_skill("parry",80);
    set_c_verbs( ({"%s��ͷ����%s","%s�ľ�������%s","%s��β��ɨ��%s"}) );
    set_c_limbs( ({"β��","��צ","����","��ͷ"}) );
    set("alt_corpse",TOBJ"boot1");
    set("death_msg","%s\n");
    set("c_death_msg","%s�ͻ��ķ�������ǰ�������ĳƺ�һ�������ˣ���������һ˫Ь��!\n");
    }