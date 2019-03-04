#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "pink ribbon", "�ۺ�ɫ˿��" );
	add( "id", ({ "ribbon","whip" }) );
	set_short( "�ۺ�ɫ˿��" );
	set_long(
		"����һ���ۺ�ɫ�ĳ�˿����������������һ��Ů��������ͷ����˿����\n"
		 "����ȴ������һ�����ص�������\n"
	);
	set( "unit", "��" );
	set( "weight", 30 );
        set("nosecond",1);
	setup_weapon( "whip", 20, 9,18);
	set( "value", ({ 320, "silver" }) );
//        set( "hit_func", "charmed" );
	set( "wield_func","wield_ribbon");
        set_c_verbs(({"%s˦��%s","%s����%s","%s����%s"}));

}

void wield_ribbon()
{
object holder;
	holder=this_player();
		
       if ((string)holder->query("gender")!="female")
        {
        tell_room( environment(holder), 
         holder->query("c_name")+"��Ҫѧ��Ů��ŤŤ����������ۺ�ɫ˿��������Ц���ˡ�\n"
		, ({holder}) );
        tell_object( holder,
         "����Ҫѧ��Ů���÷ۺ�ɫ˿��������һ�����ᣬ�Աߵ��˶�Ц��ֱ����������\n");
	::unwield();
		return ;
	}
	else
	{
        tell_room( environment(holder), 
         holder->query("c_name")+"���ŵ������ۺ�ɫ˿�����Ե�ʮ�ֽ��ġ�\n"
	, ({holder}) );
        tell_object( holder, 
         "������ۺ�ɫ˿���������Լ���ֱ���������������ĳ�����Ů��\n");
		return;
	}
	return ;
}
int charmed(object victim)
{	
	object holder;
	holder=environment(this_object());
        if( random(holder->query_perm_stat("int")+
		   holder->query_perm_stat("str"))<25) return 0;
       if( victim->query("stop_attack") ) return 0;
	if ( (string)victim->query("gender")=="female" ) return 0; 

        tell_object( victim, 
          "�ۺ�˿��ɢ����һ�����˵���������е�һ����ѣ !!\n");
        tell_object( holder, 
          "\n��ķۺ�˿��ɢ����һ�����˵����������˱���������� !!\n\n");
        tell_room( environment(holder), 
          "\�ۺ�ɫ˿����������ʹ" + victim->query("c_name") +"�޷����� !!\n\n"
	, ({ victim, this_object() }));
        victim->block_attack(6);
        victim->set_temp("msg_stop_attack", 
          "( ������ȫ����������������Ƭ�������ջ��� ! )\n" 
        );
        return 1;

}
