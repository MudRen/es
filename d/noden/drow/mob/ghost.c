
#include <../iigima.h>
inherit MONSTER;

void create()
{
       ::create();
       set_level(19);
       set_name("dynasty ghost","�Ŵ�����");
       set_short("dynasty ghost","�Ŵ�����");
       add("id",({"ghost"}));
       set_long(@C_LONG
������˾�ȿ�Ů���ӡ���Ϲų��������飬��Ȼ������
�������׺ݵĶ��飬��а���˾�ȿ�Ů����ڤ��������
������������ͼռ�����񹬡�
C_LONG
       set("unit","λ");
       set_natural_weapon(45,26,47);
       set_natural_armor(22,25,14);
       set("max_hp",1080);
       set("hit_points",1080);
       set("alignment",-1600);
       set("tactic","assault");
       set_perm_stat("str",25);
       set_perm_stat("dex",25);
       set_skill("block",100);
       set_skill("dodge",100);
       set("unbleeding",1);
       set("tactic_func","my_tactic");
       set("special_defense",(["all":45,"none":20]));
}
int my_tactic
{
       object *victim;
       if(!(victim=query_attackers())) return 0;
       if(random(20)<5){
        tell_room(environment(this_object()),
        "�����������һ�����ǧ��ֻ��ħ����������ܣ����ҷ��裡��\n"
        ,this_object());
        victim->receive_special_damage("mental",140);
        return 1;
        } else return 0;
}


