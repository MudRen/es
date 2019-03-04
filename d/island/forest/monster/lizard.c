#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(14);
    set_name("Huge Lizard","������");
    add("id",({"lizard"}) );
    set_short("������");
    set_long(@LONG
һֻ�޴�����棬�����ſ�������ǰ�����в��ϵ����ţ��ݷ���̽���������
�Ƶġ������������δ����İ׹ǣ��찡������ֻ��ʳ�ԵĴ����棬��ɵ�С����
���Է������˲���ʱ͵Ϯ��
LONG
            );
    set("unit","ֻ");
    set("alignment",-2000);
    set("weight",2000);
    set("max_hp",500);
    set("hit_points",500);
    set_natural_weapon(20,21,30);
    set_natural_armor(60,35);
    set("unbleed",1);
    set_skill("dodge",80);
    set_skill("parry",60);
    set_skill("unarmed",50);
    set_perm_stat("str",25);
    set_perm_stat("dex",23);
    set_c_verbs( ({"%s����ͷ����%s","%s����צ����%s","%s��β��ɨ��%s"}) );
    set_c_limbs( ({"β��","��צ","����","��ͷ","��ͷ"}) );
    set("alt_corpse",TOBJ"shield2");
    set("death_msg","%s\n");
    set("c_death_msg",
    "%s�ͻ��ķ�������ǰ�������ĳƺ�һ�������ˣ�һ�����֮�ᣬ��ǰֻ����һ���!\n");
}
