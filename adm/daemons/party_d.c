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
		"�㿪ʼ��֯һ��ð�ն���.��\n");
	tell_room( environment(le), 
		C_CAPNAME(le)+"��ʼ��֯һ��ð�ն���.��\n" ,le );
	give_party_token( NAME(le), le );
}

void invite_member(object le, object me)
{
	object *members, *invited;

	if( !le || !me ) return;
	if( !pointerp(invited= INVITED(le)) || !pointerp(members= MEMBERS(le)) )
		return;

	if( sizeof(invited)>=MAX ) {
		write("��Ķ������ֻ���� " + MAX + " ����.��\n");
		return;
	}

	if( member_array(me, members)!=-1 ) {
		write(C_CAPNAME(me)+"�Ѿ��������ĳ�Ա��.��\n");
		return;
	}

	if( member_array(me, invited)!=-1 ) {
		write("���Ѿ������"+ C_CAPNAME(me)+"��.��\n");
		return;
	}

	invited += ({ me });
	le->set_temp( "party_invited", invited );
	write("������"+C_CAPNAME(me)+"�������ð�ն���.��\n");
	tell_object(me, 
		C_CAPNAME(le)+"������μ�"+ to_chinese(POSS(le)) +"����.��\n"
	);
	tell_room( environment(le), 
		C_CAPNAME(le)+"����"+C_CAPNAME(me)+"����"+ to_chinese(POSS(le))+"���顡\n",
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
			C_CAPNAME(arg[0])+ "������μ�ð�ն����ʱ���Ѿ�����.��\n"
		);
		tell_object(arg[0],
			"������" + arg[3]+ "�μ�ð�ն����ʱ���Ѿ�����.��\n"
		);
		} else
		tell_object(arg[0],
			"������"+arg[3]+"�μ�ð�ն����ʱ���Ѿ�����.��\n"
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
			"���Ѿ���" + C_CAPNAME(le) + "��ð�ն����Ա֮һ��.��\n"
		);
		return;
	}
	if( sizeof(members)>=MAX ) {
		write( 
			C_CAPNAME(le)+"��ð�ն��������Ѿ�����.��\n"
		);
		return;
	}
	if( member_array(me, invited) == -1 ) {
		write(
			"�㲢û�б�����μ�"+C_CAPNAME(le)+"��ð�ն���.��\n"
	);
		return;
	}
	remove_invitation( ({ le, me, 0,C_CAPNAME(me) }) );
	members += ({ me });
	me->set_temp("leader", NAME(le));
	le->set_temp("party_members", members );
	tell_object(me,"�������"+C_CAPNAME(le)+"��ð�ն���.��\n");
	tell_object(le, C_CAPNAME(me)+"�����������ð�ն���.��\n");
	tell_room( environment(le), 
		C_CAPNAME(me)+"����"+CAPNAME(le)+"��ð�ն���.��\n",
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
		tell_object(members[i],"���ð�ն����ɢ��.��\n");
		remove_party_token( members[i] );
	}
	le->set_temp("party_members", 0 );
	le->set_temp("party_invited", 0 );
	le->set_temp("leader", 0);
//	tell_object(le, can_read_chinese(le)?
//		"���ð�ն����ɢ�ˡ�\n": "Your party has been disbanded.\n");
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
			C_CAPNAME(le)+"�����"+ to_chinese(POSS(le)) +"ð�ն����г���.��\n"
		);
		tell_object(le,"�㽫"+C_CAPNAME(me)+"�Ӷ����г���.��\n");
	} else {
		tell_object(me,"������"+CAPNAME(le)+"��ð�ն���.��\n");
		tell_object(le, C_CAPNAME(me)+"���������ð�ն���.��\n");
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
		tell_object(members[i], C_CAPNAME(me)+"��Ϊ��ð�ն����������.��\n");
	}
	me->set_temp( "prty_members", MEMBERS(le) );
	me->set_temp( "party_invited", INVITED(le) );
	le->set_temp( "party_members", 0 );
	le->set_temp( "party_invited", 0 );
	me->set_temp("leader", NAME(me));
	tell_object(me, "��������ð�ն������������.��\n");
}

void party_list(object le) 
{
	object *members;
	int i, sz;

	if( !le || !pointerp(members= MEMBERS(le)) ) return;
	sz = sizeof(members);
	write( "���ð�ն��鹲�� " + sz + " ����Ա:\n");
	write("  "+C_CAPNAME(le)+" [����]\n");
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
					"���ð�ն���򵹵��ˣ���ֵ� " + j + " �㾭�顡\n"
				);
			}
			return;
		}
	}
	me->gain_experience(exp);
	tell_object( me, "��õ� " + exp + " �㾭��.��\n");
}
