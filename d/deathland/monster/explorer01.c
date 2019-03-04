
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(13);
	set_name( "orc explorer Lawierda","������̽�ռ�������");
	add ("id", ({ "orc", "explorer","lawierda" }) );
	set_short("������̽�ռ�������");
	set_long(@DESC
������̽�ռ�������,һ��ϲ��ð�յİ�����,�������й��ܶ�ط�.
�������˵Ī���°��˹��ȵĿ�ӳ������Ƹ�,���Ը�������Ѱ��.
DESC
    );
    set("alignment",-400);
    set( "gender", "male" );
    set( "race", "orc" );
    set( "unit", "��" );
	set_perm_stat( "str", 20 );
	set ("wealth", ([ "silver": 100 ]) );
	set_natural_weapon(26,10,23);
	set_natural_armor(57,17);
    set ("weight", 300);
    set ("chat_chance", 15);
    set("chat_output",({
        "�������̽���߻Ӷ�������ȭͷ,һ�����ŵ�����.\n"
        }));
    set_skill("dagger",80);
    set_skill("dodge",100);
    set( "inquiry", ([
         "lucksis" : "@@ask_lucksis",
         ]) );
    wield_weapon(Weapon"/dagger02");     
}

void ask_lucksis(object who)
{
     if (!(who->query_temp("lucksis_quest")) || (int)(who->query_temp("lucksis_quest/ask"))==0 ) 
       tell_object(who,@MSG1
������˵:�Ҳ�֪��Ϊ����Ҫ������.
����һ�����ĵ�����.�Ҳ���������
MSG1
                       );
     else
       {
         tell_object(who,@MSG2
������˵:��������ϣ˿������?
�������Ѿ���һ��������.��Ȼ��ʱ�Һ�����һ�ο��ֵ�ʱ��,
�������ڵ���ֻ��ð������Ȥ,������,ǰ��δ֪������,����
���������ʹ̼�,�Ƕ������һ���°�!
������תͷ����Ѱ�����������.


һ��ֻ��׷��̼����˶�춱��˵�������������?
�������ڵ�������������ϣ˿��ʶ���������Ѿ���Ȼ��ͬ��.
MSG2
                    );
         who->set_temp("lucksis_quest/lawierda",1);             
       }
     return;
}

void die()
{
	object killer;
	killer = query("last_attacker");
	killer->set_explore( "deathland#34" );
	::die();
}
