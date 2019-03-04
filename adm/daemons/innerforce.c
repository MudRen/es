// innerforce.c

int query_effect(string type)
{
	switch (type) {
		case "thrusting"  : return 10; break;
		case "longblade"  : return  9; break;
		case "shortblade" : return  8; break;
		case "dagger"     : return  8; break;
		case "whip"       : return  5; break;
		case "axe"        : return  3; break;
		case "chain"      : return  3; break;
		case "polearm"    : return  3; break;
		case "blunt"      : return  2; break;
		case "wand"       : return  0; break;
		default           : return  0; break;
	}
}

varargs int force_apply(object me, object victim, object weapon)
{
	int fp, fe, v_fp, effect, damage;
	string ft, c_msg;

	if( !me || !victim ) return 0;

	fp = (int)me->query("force_points");
	v_fp = (int)victim->query("force_points");
	if( !fp || fp < 0 || fp < (v_fp/2) ) return 0;
	
	if( weapon ) {
		if( userp(me) ) {
			if( !me->query("use_inner_force") ) return 0;
			effect = query_effect((string)weapon->query("type"));
		} else
			effect = 10;
		me->add( "force_points", -effect );
		damage = (int)weapon->query("max_damage") * 
				 (fp - (v_fp/2)) * effect / 20000;
		damage=damage*(100 - (int)victim->query_special_defense("monk"))/100;
                victim->receive_damage( damage );
		return damage;
	} else {
		fe = (int)me->query("force_effect");
		if( userp(me) )
			damage = (fp>fe)? fe: fp;
		else if( v_fp )
			damage = (fp - (v_fp/2)) / 200;
		else
			damage = fp / 100;
		me->add( "force_points", -damage );
                damage += random(damage * 2);
		damage=damage*(100 - (int)victim->query_special_defense("monk"))/100;
		if( ft= (string)me->query("force_type") )
			victim->receive_special_damage( ft, damage );
		else
                        victim->receive_damage( damage );
		switch ( damage / 10 ) {
			case 0 : c_msg = "��΢��";     break;
			case 1 : c_msg = "һ��";       break;
			case 2 : c_msg = "��С��";     break;
			case 3 : c_msg = "��Ϊ���ص�"; break;
			case 4 : c_msg = "���ص�";     break;
			case 5 : c_msg = "�൱���ص�"; break;
			case 6 : c_msg = "ʮ�����ص�"; break;
			default: c_msg = "������";     break;
		}
		if( damage ) {
		  tell_object( victim,
                         sprintf("�㱻%s����������, ����%s����!\n",me->query("c_name"),c_msg)
		  );
		  tell_object( me, 
                        sprintf("����������%s����, �Է�����%s����!\n",victim->query("c_name"),c_msg)
		  );
		}
	}
}
