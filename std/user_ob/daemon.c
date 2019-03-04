// This is the actual user object. All default functions are defined in
// /std/user.c. Only those varies with races are redefined here. The
// inheriting relations are:
//
//   misc... -> body.c -> living.c -> user.c -> human.c ( for example.)
//
// This extension is started by Annihilator Aug 17, 1994.

#include <mudlib.h>

inherit USER;
inherit "/std/races/daemon";

void consistency_check()
{
	// Do common check first.
	user::consistency_check();

	// Setup extra properties for Race Daemon.
	daemon::setup_race_body();
	add_action("do_claw","claw");
}

int do_claw(string str)
{
	object victim;
	if ( ! str )
		return notify_fail("����ץ˭��\n");
	if ( !victim = present(str,environment(this_object())))
		return notify_fail("����û�н� "+str+" �ġ�\n");

	if ( !living(victim) ) {
		tell_object(this_object(),sprintf("����%sһ����ץ��ĥĥצ�ӡ�\n",victim->query("short")));
		tell_room(environment(this_object()),
			sprintf("%s��%s��һ����ץ��������ĥצ�ӡ�\n",
				query("c_name"),victim->query("short"))
			  ,this_object());
		return 1;
	}
	if ( userp(victim) && (((int)victim->query_level()<5) || ((int)this_object()->query_level()<5)) )
		return notify_fail("�͵ȼ���Ҳ���PK !!\n");

	if (victim->query_temp("be_clawed"))
		return notify_fail("���ľ����Ժܸߣ����������֡�\n");
	if ( victim->query("no_attack") )
		return notify_fail("�������۸��� ... ");
	victim->set_temp("be_clawed",1);

	tell_object(this_object(),
		    sprintf("/n�����ĵ��ߵ�%s�ı��ᣬ�ݺݵ���������ץ��ȥ ...",
			    victim->query("short"))
		    );
	tell_object(victim,sprintf("/n%s�������µ��߹�����ͻȻ��������צ�ݺݵ�ץ�㡣",
				query("c_name"))
		    );
	tell_room(environment(this_object()),
		  sprintf("/n%s�����ߵ�%s��ߣ�ͻȻһצ��������ץ��ȥ��",
			  query("c_name"),victim->query("short")),
		  ({ this_object(),victim })
		  );
	if ( random(query_level()) < (int)victim->query_level()/2) {
		tell_room(environment(this_object()),
			  set_color("���Ǳ������� !!\n","HIY"),({})
			  );
		victim->kill_ob(this_object());
		return 1;
	}
	tell_room(environment(this_object()),
		  set_color("��ʱѪ���Ľ� !!\n","HIR"),({})
		  );
		victim->kill_ob(this_object());
		victim->receive_damage(random(query_level()*2));
		return 1;
}
		
