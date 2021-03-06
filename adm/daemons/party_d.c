// File: /adm/daemons/party_d.c
// written by Zeus, 22/04/1993
// this party daemon is written for TMI-2 mudlib
// It should be used with /cmds/std/_party.c

#define NAME(x) (string)x->query("name")
#define LEADER(x) (string)x->query_temp("leader")
#define MEMBERS(x) x->query_temp("party_members")
#define INVITED(x) x->query_temp("party_invited")
#define CAPNAME(x) capitalize((string)x->query("name"))
#define C_CAPNAME(x) (string)x->query("c_name")
#define POSS(x) possessive((string)x->query("gender"))
#define TIMEOUT 60
#define MAX 4
#define TOKEN "/d/std/objects/party_token"

void create()
{
	seteuid( getuid() );
}

void give_party_token(string leader, object user)
{
	object token;

	if( !user ) return;
	token = new( TOKEN );
	if( !token ) return;
	token->set_party_name( leader );
	token->move( user );
	return;
}

void remove_party_token(object user)
{
	object token;

	if( !user ) return;
	if( !(token=present("party_token", user)) ) return;
	token->remove();
}

void form_party(object le)
{
	if( !le ) return;
	if( MEMBERS(le) ) return;
	le->set_temp( "party_members", ({ le }) );
	le->set_temp( "party_invited", ({ }) );
	le->set_temp( "leader", NAME(le) );
	tell_object(le,
		"你开始组织一个冒险队伍.　\n");
	tell_room( environment(le), 
		C_CAPNAME(le)+"开始组织一个冒险队伍.　\n" ,le );
	give_party_token( NAME(le), le );
}

void invite_member(object le, object me)
{
	object *members, *invited;

	if( !le || !me ) return;
	if( !pointerp(invited= INVITED(le)) || !pointerp(members= MEMBERS(le)) )
		return;

	if( sizeof(invited)>=MAX ) {
		write("你的队伍最多只能有 " + MAX + " 个人.　\n");
		return;
	}

	if( member_array(me, members)!=-1 ) {
		write(C_CAPNAME(me)+"已经是你队伍的成员了.　\n");
		return;
	}

	if( member_array(me, invited)!=-1 ) {
		write("你已经邀请过"+ C_CAPNAME(me)+"了.　\n");
		return;
	}

	invited += ({ me });
	le->set_temp( "party_invited", invited );
	write("你邀请"+C_CAPNAME(me)+"加入你的冒险队伍.　\n");
	tell_object(me, 
		C_CAPNAME(le)+"邀请你参加"+ to_chinese(POSS(le)) +"队伍.　\n"
	);
	tell_room( environment(le), 
		C_CAPNAME(le)+"邀请"+C_CAPNAME(me)+"加入"+ to_chinese(POSS(le))+"队伍　\n",
		({ le, me }) );
	call_out("remove_invitation", TIMEOUT, ({ le, me, 1 ,C_CAPNAME(me) }) );
}

void remove_invitation(mixed arg)
{
	object *invited;

	if( !objectp(arg[0]) || !pointerp(invited=INVITED(arg[0])) ||
		member_array(arg[1], invited)==-1 )
		return;
	if( arg[2] ) {
	  if ( ! nullp(arg[1]) ) {
		tell_object(arg[1],
			C_CAPNAME(arg[0])+ "邀请你参加冒险队伍的时限已经到了.　\n"
		);
		tell_object(arg[0],
			"你邀请" + arg[3]+ "参加冒险队伍的时限已经到了.　\n"
		);
		} else
		tell_object(arg[0],
			"你邀请"+arg[3]+"参加冒险队伍的时限已经到了.　\n"
		);
		}	
	invited -= ({ arg[1] });
	arg[0]->set_temp( "party_invited", invited );
}

void add_member(object le, object me)
{
	object *members, *invited;

	if( !le || !me ) return;
	if( !pointerp(members= MEMBERS(le)) || !pointerp(invited= INVITED(le)) )
		return;
	if( member_array(me, members)!= -1 ) {
		write( 
			"你已经是" + C_CAPNAME(le) + "的冒险队伍成员之一了.　\n"
		);
		return;
	}
	if( sizeof(members)>=MAX ) {
		write( 
			C_CAPNAME(le)+"的冒险队伍人数已经满了.　\n"
		);
		return;
	}
	if( member_array(me, invited) == -1 ) {
		write(
			"你并没有被邀请参加"+C_CAPNAME(le)+"的冒险队伍.　\n"
	);
		return;
	}
	remove_invitation( ({ le, me, 0,C_CAPNAME(me) }) );
	members += ({ me });
	me->set_temp("leader", NAME(le));
	le->set_temp("party_members", members );
	tell_object(me,"你加入了"+C_CAPNAME(le)+"的冒险队伍.　\n");
	tell_object(le, C_CAPNAME(me)+"决定加入你的冒险队伍.　\n");
	tell_room( environment(le), 
		C_CAPNAME(me)+"加入"+CAPNAME(le)+"的冒险队伍.　\n",
		({ me, le }) );
	give_party_token( NAME(le), me );
	return;
}

void disband_party(object le)
{
	object *members;
	int i, sz;

	if( !le ) return;
	if( !pointerp(members= MEMBERS(le)) ) return;
	sz = sizeof(members);
	for(i = 0; i < sz; i++) {
		if( !members[i]) continue;
		members[i]->set_temp("leader", 0);
		tell_object(members[i],"你的冒险队伍解散了.　\n");
		remove_party_token( members[i] );
	}
	le->set_temp("party_members", 0 );
	le->set_temp("party_invited", 0 );
	le->set_temp("leader", 0);
//	tell_object(le, can_read_chinese(le)?
//		"你的冒险队伍解散了　\n": "Your party has been disbanded.\n");
}

void disband_member(object le, object me, int flag)
{
	object *members;

	if( !le || !me ) return;
	if( !pointerp(members = MEMBERS(le)) ||
	member_array(me, members) == -1) return;
	members -= ({ me });
	le->set_temp("party_members", members );
	me->set_temp("leader", 0);
	if(flag) {
		tell_object(me, 
			C_CAPNAME(le)+"将你从"+ to_chinese(POSS(le)) +"冒险队伍中除名.　\n"
		);
		tell_object(le,"你将"+C_CAPNAME(me)+"从队伍中除名.　\n");
	} else {
		tell_object(me,"你脱离"+CAPNAME(le)+"的冒险队伍.　\n");
		tell_object(le, C_CAPNAME(me)+"脱离了你的冒险队伍.　\n");
	}
	remove_party_token( me );
	return;
}

void check_party(object le)
{
	object ob;

	if( !le || !(LEADER(le)) ) return;
	if( (LEADER(le)) == (NAME(le)) ) {
		disband_party(le);
		return;
	}
	ob = find_living(LEADER(le));
	if(!ob) return;
	disband_member(ob, le, 0);
}

object *query_members(object le) 
{
	if( !le ) return 0;
	return MEMBERS(le);
}

void change_leader(object le, object me) 
{
	object *members;
	int i, sz;

	if( !le || !me || !pointerp(members= MEMBERS(le)) ||
		member_array(me, members)==-1 ) return;
	sz = sizeof(members);
	for(i = 0; i < sz; i++) {
		if(!members[i] || members[i]==me ) continue;
		members[i]->set_temp("leader", NAME(me));
		tell_object(members[i], C_CAPNAME(me)+"成为你冒险队伍的新领袖.　\n");
	}
	me->set_temp( "prty_members", MEMBERS(le) );
	me->set_temp( "party_invited", INVITED(le) );
	le->set_temp( "party_members", 0 );
	le->set_temp( "party_invited", 0 );
	me->set_temp("leader", NAME(me));
	tell_object(me, "你现在是冒险队伍的新领袖了.　\n");
}

void party_list(object le) 
{
	object *members;
	int i, sz;

	if( !le || !pointerp(members= MEMBERS(le)) ) return;
	sz = sizeof(members);
	write( "你的冒险队伍共有 " + sz + " 个成员:\n");
	write("  "+C_CAPNAME(le)+" [领袖]\n");
	for(i = 0; i < sz; i++) {
		if(!members[i] || members[i]==le) continue;
		write("  "+C_CAPNAME(members[i])+"\n");
	}
}
// Modified by Yueh to consider piety in share experience
void share_experience(object me, int exp)
{
	object leader, *members;
	int i, j, l, level, high_level,pie;

	if( !me ) return;
	leader = find_player(LEADER(me));
	high_level = 0;
	if( leader ) {
		members = MEMBERS(leader);
		for( l=0, i=0; i<sizeof(members); i++ ) {
			if( !members[i] || !present(members[i], environment(me)) ) continue;
			level = (int)members[i]->query_level();
			if ( level > high_level ) high_level = level;
			pie= (int)members[i]->query_stat("pie");
			l = l+2*level+pie;
			if( members[i]==me ) l = l+2*level+pie;
		}
		if( l > 0 ) {
			for( i=0; i<sizeof(members); i++ ) {
				if( !members[i] || !present(members[i], environment(me)) ) continue;
				level = (int)members[i]->query_level();
				pie= (int)members[i]->query_stat("pie");
				j = exp * (2*level+pie) / l;
				if( members[i]==me ) j *= 2;
				if( j<1 ) j = 1;
				if ( level+8  <= high_level ) j =0;
				members[i]->gain_experience(j);
				tell_object( members[i], 
					"你的冒险队伍打倒敌人，你分到 " + j + " 点经验　\n"
				);
			}
			return;
		}
	}
	me->gain_experience(exp);
	tell_object( me, "你得到 " + exp + " 点经验.　\n");
}
