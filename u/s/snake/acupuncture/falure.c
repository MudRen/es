// This is a acupuncture effect object . rewrite from power-boost
//  spell By Annihilator@Eastern.Stories
// 
// acupuncture by Indra@ES

int query_sp_cost(int eff_lv,int skill_lv)
{
                  return eff_lv * 10 + (5-skill_lv)*2;               
}

int query_need_skill() { return 2 ; }


int cast(int level, object target)
{
	int delay_time;
	object me ;

        me = this_player();
	
//	if( me->query("npc") && me->query("magic_delay") )
//	    delay_time = (int)me->query("magic_delay");
//	else
	  
        delay_time = 3;
	me->block_attack(delay_time);
	me->set_temp("cast_busy", 1);
	target->delete("acupuncted_pts") ;
	target->delete_temp("acupuncted_pts") ;	
	
	write(  "你随地坐下并牵起"+target->query("c_name")+
		"的手,缓缓将气送出去。\n" );
	tell_room( environment(me), ({
		me->query("c_name") + "随地坐下并牵起"
		+target->query("c_name")+"的手,缓缓将气送出去。\n"}),
		me ,target);
        tell_object(target,me->query("c_name") + 
                           "随地坐下并牵起你的手,缓缓将气送进来。\n" ) ;

	call_out( "effect", delay_time, level, me, target );
	return 1;
}

void effect(int level, object caster, object dest)
{
	int speed, duration;

        caster->set_temp("cast_busy", 0);
	if( !dest || !present(dest, environment(caster)) ) {
	  tell_object( caster, 
	    "不知怎麽的,也许是觉得你是个蒙古大夫。总之,你的患者走掉了。\n" 
	  );
	  return;
	}
	
	if( dest->query_temp("effect/windex") ) {
		tell_object( dest,
			"你觉得体内的血气开始快速流动，但是好像并没有什麽不同....。\n"
		);
	} else {
		tell_object( dest,
			"你觉得体内的血气开始沸腾，而周遭的人们好像都在慢动作的状态中！\n"
		);
		speed = level ;
		if( caster == dest )
			duration = level * 50 + (int)caster->query_stat("pie") * 4;
		else
			duration = level * 40 + (int)caster->query_stat("pie") * 4;
		dest->modify_stat("dex", speed);
		dest->set_temp("effect/windex", 1);
		call_out( "expire", duration, dest, speed );
	}
	tell_room( environment(dest), ({
		"你吓然发现"+dest->query("c_name")+"的动作快得夸张, \n"
		"到处都是他移动後留下的残像。\n"}),
		dest );
}

void expire( object player, int speed)
{
    if( !player ) return;
	tell_object( player,
		"你觉得你的速度慢了下来，同时气血的流动变得缓和....。\n" );
	player->modify_stat("dex", -speed);
	player->set_temp("effect/windex", 0 );
}


