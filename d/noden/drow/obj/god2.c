#include <mudlib.h>

inherit WEAPON;
void create()
{
	set_name( "@@name","������Ļƻ衻" );
         add("id",({"sword","ragnarok"}));
	set_short( "@@short" );
	set_long(@LONG
�����ڵĳ����Ľ����ϲ����˰���ʯ����������������Χ��
���������ϵ���ɫ���۰��ڰ��ڣ�����͸¶����⣬�ƺ�������
����֪��������
LONG
		);
	set( "unit","��" );
   set( "type", "longblade" );
   set( "weapon_class",40 );
   set( "min_damage", 16 );
   set( "max_damage", 33 );
	set( "weight",165 );
        set( "no_sale",1);
        set( "wield_func", "body_look" );
	set( "value",({ 9600,"silver" }) );        
	set( "hit_func","thunder_damage" );
}

string name(){ return set_color ("Ragnarok","HIY");}
string short(){ return set_color ("������Ļƻ衻","HIY"); }

int thunder_damage(object victim,int damage)
{
	object holder;
   int dam, max, mysp, mytp, mykar, tarkar;
	string msg1,msg2,him,me;

   dam = environment(this_object())->query_stat("str");
   mysp = environment(this_object())->query("spell_points");
   mytp = environment(this_object())->query("talk_points");
	if ( !victim ) return 0;
	if( !(holder = environment(this_object())) || !living(holder) ) return 0;
   if( mysp < 21 || mytp < 42 ) return 0;
   if ( (int)holder->query_skill( "longblade" )<100 )
	{
	tell_object( holder,"\n������Ļƻ衻�ķ�ӡ֮�۷���һ������ʹ���˫�ۡ�\n" );
   holder->receive_damage( dam );
	victim->set( "last_attacker",holder );
        return 0;
	}
	else
	{
	mykar = environment(this_object())->query_stat("kar");
        tarkar = victim->query_stat("kar");
        max = mykar - tarkar;
	if( max < 0 ) max = 0;
        if( random(mykar) < 9 ) return 0;
	him=victim->query( "c_name" );
	me=holder->query( "c_name" );
	tell_object( holder,set_color("\n������Ļƻ衻�ķ�ӡ֮�ۺ�Ȼ�ſ����ٻ�һ����������"+him+"����\n\n","HIB") );
	tell_object( victim,
"\n"+me+"�ٻ�һ�����״������ͷ�����㱻�����ð���ǣ�ȫ����ʹ��\n\n" );
	tell_room( environment(holder),"\n��Ȼһ����죡��������Ļƻ衻�ٻ����׽�"+him+"���ɽ�̿����\n\n",({ holder,victim }) );
   holder->add( "spell_points", -max-2 );
   holder->add( "talk_points", -max*2-4 );
   victim->receive_special_damage( "divine", dam+max );
	victim->set( "last_attacker",holder );
   return dam+max;
   }
}

void body_look()
{
 object holder;

 holder = environment(this_object());
 tell_object( holder,set_color(
    "\nʯ�����з�����â��������Ѹ�ٻ�������ز���ס�������\n\n","HIB"));
   set("extra_look",set_color(
   "һֻֻʯ�������Ĳ�����$N�������ϣ���ͣ��Ť��������\n","HIG"));
}	

// ���⹥������:
// ������Լ 1/3, ����˺� 31(str) + 14 = 45
