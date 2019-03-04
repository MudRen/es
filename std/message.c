/*
Message: ������һЩ��������ѶϢ��д��
Wrote by EGA, 11-21-1994
��ӹ���ӳ�Ч�����ݳ�	/EGA, 3-8-1995
*/

/* Document
NAME
	emote - ��һ������������ת�����ʵ������ִ��͸��ڳ�����
	
SYNOPSIS
	varargs void emote( string format, object me, 
						object where, object victim);
DESCRIPTION
	format ��һ�������ʽ���ִ�, ������ $NS, $NO �ȷ��Ŵ�����
	�ߵ����֡�������������ֵȡ�emote ���������ĸ������������
	�ִ����ʵ��Ĵ���, �����������ѶϢ�͸� me, victim, �Լ� where
	��������ˡ�
	me �Ƕ�����, victim ���Ƕ����Ķ���, where ���Ƕ��������ķ���
	
	victim ������ȥ, ��ʱ $NO, $GO ����������������Ч��
	
	where �� victim ����һ����ȥ, ��ʱ where ���Զ����趨Ϊ me 
	���ڵķ��䡣
	
	format ����õĲ�������:
	$NS		me ������
	$NO		victim ������
	$GS		me �Ĵ�����, ���Ա�Ϊ����������
	$GO		victim �Ĵ�����
	
	Ҫʹ�� emote ����, ���������� object ��
	inherit "/std/message.c";
	�������ǰ���� include <mudlib> �Ļ�, ��Ҳ����д��:
	inherit MESSAGE;
	���˱Ƚ��Ƽ����ߡ�
               
EXAMPLE
	emote( "$NŞ��$GS�Ľ�, ��$NO��ƨƨ���ص�����ȥ\n", ppla, 
			environment(ppla), pplb );
	ppla ���ῴ��: ��̧������Ľ�, �� pplb ��ƨƨ���ص�����ȥ
	pplb ��ῴ��: ppla ̧�������Ľ�, �����ƨƨ���ص�����ȥ
	��� ppla ���еĻ�, �����е���������ῴ��: ppla ̧�������Ľ�, 
		�� pplb ��ƨ�����ص�����ȥ
	
SEE ALSO
	emote_message
*/

/*
NAME
	emote_message_me
	emote_message_victim
	emote_message_other - ��һ������������ת�����ʵ�������
	
SYNOPSIS
	varargs string emote_message_me( string format, object me, 
						object where, object victim);
	varargs string emote_message_victim( string format, object me, 
						object where, object victim);
	varargs string emote_message_other( string format, object me, 
						object where, object victim);
DESCRIPTION
	�� emote ��ͬ, emote_message_xx �Ὣ format ����ִ����ʵ���
	���������������ὫѶϢֱ�ӳ�ȥ, ������Ϊһ������ֵ, �ú�����
	����ʦ�Լ�����
	emote_message_me �����ص����� me ���ῴ��ѶϢ
	emote_message_victim �����ص������� victim ���ῴ��ѶϢ
	emote_message_other �����ص������ڳ����Թ������ῴ��ѶϢ
	
	��ʱ��, һ�������Ķ�������кܶ������һ��, ��ʱ emote ����
	��ʹ�á�������ÿ�������Ķ�����һ�� emote_message_victim()
	���䴫��ֵ�� tell_object() �Ķ������ܵõ���ȷ�Ľ����
	
	emote_message ϵ�еĺ���Ҳ����ʡ�Ե� where �� victim, ����
	����ʡ�� victim ʱ, emote_message_victim �ᴫ�ؿ��ִ�����Ϊ
	û�ж����Ķ����ˡ�
	
	����, me �� victim �����������Է��롸����������, ���Ǵ�
	ʱ format �ִ�������$GS, $GO ��������, ������޷�Ԥ�ϡ�
	
SEE ALSO
	emote
*/

//PUBLIC FUNCTIONS
varargs	void	emote( string format, object me, object where, object victim);
varargs	string	emote_message_me( string format, object me, object where, 
				object victim);
varargs	string	emote_message_victim( string format, object me, object where,
				object victim);
varargs	string	emote_message_other( string format, object me, object where, 
				object victim);
varargs void	step_tell_object( mixed ob, string msg, int time_step);
varargs void	step_tell_room( mixed room, string msg, mixed exclude,
				int time_step);
varargs	void	step_object_msg( mixed ob, string message, object me, 
				object player);
varargs	void	step_room_msg( mixed room, string message, mixed exclude,
				object me, object player);

//VARIBLES
mapping	gender = (["male" : "��", "female" : "��", "neuter" : "��" ]);

varargs	void	emote( string format, object me, object where, object victim)
{
	string	me_message, victim_message, other_message;
	
	if	(where && victim)	{
//�����ж��ߵ�����
		me_message = replace_string( format, "$NS", "��");
		victim_message = replace_string( format, "$NS", me->query("c_name") );
		other_message = replace_string( format, "$NS", me->query("c_name") );
//�����ж����������
		me_message = replace_string( me_message, "$NO", victim->query("c_name") );
		victim_message = replace_string( victim_message, "$NO", "��");
		other_message = replace_string( other_message, "$NO", victim->query("c_name") );
//�����ж��ߵ��Ա�
		me_message = replace_string( me_message, "$GS", "��" );
		victim_message = replace_string( victim_message, "$GS", gender[me->query("gender")] );
		other_message = replace_string( other_message, "$GS", gender[me->query("gender")] );
//���붯��������Ա�
		me_message = replace_string( me_message, "$GO", gender[victim->query("gender")] );
		victim_message = replace_string( victim_message, "$GO", gender[victim->query("gender")] );
		other_message = replace_string( other_message, "$GO", "��" );
//����ѶϢ���ڳ�����
		tell_object( me, me_message );
		tell_object( victim, victim_message );
		tell_room( where, other_message, ({me, victim}) );
	}
	else if (!victim)
	{
//�����ж��ߵ�����
		me_message = replace_string( format, "$NS", "��");
		other_message = replace_string( format, "$NS", me->query("c_name") );
//�����ж��ߵ��Ա�
		me_message = replace_string( me_message, "$GS", "��" );
		other_message = replace_string( other_message, "$GS", gender[me->query("gender")] );
//����ѶϢ���ڳ�����
		if (!where)	where = environment(me);
		tell_object( me, me_message );
		tell_room( where, other_message, me );
	}
}

// emote_message_me: ����һ���������߱����ѶϢ
varargs	string	emote_message_me( string format, object me, object where, object victim)
{
	string	me_message;
	mapping	gender = (["male" : "��", "female" : "��", "netural" : "��" ]);
	
	
	if (!format || !me) return "";
	if	(where && victim)	{
		me_message = replace_string( format, "$NS", "��");
		me_message = replace_string( me_message, "$NO", victim->query("c_name") );
		me_message = replace_string( me_message, "$GS", "��" );
		me_message = replace_string( me_message, "$GO", gender[victim->query("gender")] );
	}
	else if (!victim)
	{
		me_message = replace_string( format, "$NS", "��");
		me_message = replace_string( me_message, "$GS", "��" );
	}
	return me_message;
}

// emote_message_victim: ����һ�������������ѶϢ
varargs	string	emote_message_victim( string format, object me, object where, object victim)
{
	string	victim_message;

	if (!format || !me) return "";	
	if	(where && victim)	{
		victim_message = replace_string( format, "$NS", me->query("c_name") );
		victim_message = replace_string( victim_message, "$NO", "��");
		victim_message = replace_string( victim_message, "$GS", gender[me->query("gender")] );
		victim_message = replace_string( victim_message, "$GO", gender[victim->query("gender")] );
	}
	else if (!victim)
	{
		victim_message = "";
	}
	return victim_message;
}

// emote_message_other: ����һ�����Թ��ߵ�ѶϢ
varargs	string	emote_message_other( string format, object me, object where, object victim)
{
	string	other_message;
	
	if (!format || !me) return "";
	if	(where && victim)	{
		other_message = replace_string( format, "$NS", me->query("c_name") );
		other_message = replace_string( other_message, "$NO", victim->query("c_name") );
		other_message = replace_string( other_message, "$GS", gender[me->query("gender")] );
		other_message = replace_string( other_message, "$GO", "��" );
	}
	else if (!victim)
	{
		other_message = replace_string( format, "$NS", me->query("c_name") );
		other_message = replace_string( other_message, "$GS", gender[me->query("gender")] );
	}
	return	other_message;
}

varargs void	step_tell_object( mixed ob, string msg, int time_step)
{
	string	*msg_array;
	int		i;

	if (!time_step) time_step = 2;
	msg_array = explode( msg, "\n" );
	for ( i = 0; i < sizeof(msg_array); i++ )
	{
		call_out( "step_object_msg", i * time_step, ob, msg_array[i]+ "\n", 
					this_object(), this_player() );
	}
}

varargs void	step_tell_room( mixed room, string msg, mixed exclude,
				int time_step)
{
	string	*msg_array;
	int		i;
	
	if (!time_step) time_step = 2;
	msg_array = explode( msg, "\n" );
	for ( i = 0; i < sizeof(msg_array); i++ )
	{
		call_out( "step_room_msg", i * time_step, room, msg_array[i]+"\n", 
					exclude, this_object(), this_player() );
	}
}

varargs	void	step_object_msg( mixed ob, string message, object me, 
				object player)
{
	if ( (!me) || (!ob) )	return;
	tell_object( ob, message );
}

varargs	void	step_room_msg( mixed room, string message, mixed exclude,
				object me, object player)
{
	if ( (!me) || (!room) )	return 0;
	tell_room( room, message, exclude);
}
