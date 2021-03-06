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
		return notify_fail("你想抓谁？\n");
	if ( !victim = present(str,environment(this_object())))
		return notify_fail("这里没有叫 "+str+" 的。\n");

	if ( !living(victim) ) {
		tell_object(this_object(),sprintf("你在%s一阵乱抓，磨磨爪子。\n",victim->query("short")));
		tell_room(environment(this_object()),
			sprintf("%s在%s上一阵乱抓，好像在磨爪子。\n",
				query("c_name"),victim->query("short"))
			  ,this_object());
		return 1;
	}
	if ( userp(victim) && (((int)victim->query_level()<5) || ((int)this_object()->query_level()<5)) )
		return notify_fail("低等级玩家不能PK !!\n");

	if (victim->query_temp("be_clawed"))
		return notify_fail("他的警觉性很高，不容易下手。\n");
	if ( victim->query("no_attack") )
		return notify_fail("不可以欺负他 ... ");
	victim->set_temp("be_clawed",1);

	tell_object(this_object(),
		    sprintf("/n你悄悄的走到%s的背後，狠狠地往他身上抓下去 ...",
			    victim->query("short"))
		    );
	tell_object(victim,sprintf("/n%s若无其事的走过来，突然用他的利爪狠狠地抓你。",
				query("c_name"))
		    );
	tell_room(environment(this_object()),
		  sprintf("/n%s慢慢走到%s身边，突然一爪往他身上抓下去。",
			  query("c_name"),victim->query("short")),
		  ({ this_object(),victim })
		  );
	if ( random(query_level()) < (int)victim->query_level()/2) {
		tell_room(environment(this_object()),
			  set_color("但是被发现了 !!\n","HIY"),({})
			  );
		victim->kill_ob(this_object());
		return 1;
	}
	tell_room(environment(this_object()),
		  set_color("霎时血花四溅 !!\n","HIR"),({})
		  );
		victim->kill_ob(this_object());
		victim->receive_damage(random(query_level()*2));
		return 1;
}
		
