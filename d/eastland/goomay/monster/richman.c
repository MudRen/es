
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_name( "Chang the richman", "Ǯ����" );
        add ("id",({ "chang","richman"}));
        set_short( "Ǯ����");
        set("unit","��");
        set_level(10);
        set_long(
@C_LONG
�㿴��һ����С���ݵ��ˣ�������ʹ�Լ��ʮ���꣬��Ȼ����һ˫����
���������֮��û�������ر�����ע��ĵط���������ȴ�Ǵ���������
�����һ�׸���Ǯ���ࡣ��������Ȥ����׬Ǯ�����������ں�������
���������ǵ�׬Ǯ�ƻ������û�µĻ�������ò�Ҫ�������ǡ�
C_LONG
);
        set ("gender", "male");
        set ("race", "human");
        set ("tactic_func","kill_me");
}
void disappear()
{
	tell_room(environment(),"Ǯ����ӻ�ȭ���е� : ���Һݺݵ����� !! Ȼ������ˡ�\n",
			this_object());
	this_object()->remove();		
}
int kill_me()
{
	object ob1,ob2,victim;	
	if ( query("killed") ) return 1;
	victim = this_object()->query_attacker();
        tell_room( environment(), 
         "Ǯ���������ؽе��������˰� !! �������֪����ļһ���ȥ !!����\n"
        ,this_object() );

        ob1 = new(Mob"bodyguard" );
        ob1 ->move( environment() );
        ob2 = new(Mob"watchdog" );
        ob2 ->move( environment() );
		ob1->kill_ob(victim);
		ob2->kill_ob(victim);
		this_object()->set("killed",1);	
		call_out("disappear",2);
        return 1;
}

