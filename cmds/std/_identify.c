//#pragma save_binary

// Identify command
// By Annihilator@Eastern.Stories

void identify_weapon(object obj, int skill)
{
	int wc, dam;
	string type;

	wc = (int)obj->query("weapon_class");
	dam = (int)obj->query("min_damage") + (int)obj->query("max_damage");
	type = (string)obj->query("type");
	skill += (int)this_player()->query_skil(type) / 3;

	// Failed, so make the information garbage
	if( skill < wc + random(wc/2) + dam/2 ) {
		wc = wc/2 + random(wc);
		dam = dam/2 + random(dam);
	}

	write( 
		"����һ��" + to_chinese(type) + "��\n");

		if( wc <= 5 ) write( "����˵��������������˵�Ǽ�װ��Ʒ��\n" );
		else if( wc <= 10 ) write( "����������������ǿ���Դպ���ʹ�á�\n" );
		else if( wc <= 15 ) write( "����Ʒ�ʿ������ƺ�ֵ�û�Ǯȥ��\n" );
		else if( wc <= 20 ) write( "����ľ��飬����������������Ǹ߼�Ʒ��\n" );
		else if( wc <= 25 ) write( "ƾ����˵�������������һ������Ŀ����ν�ġ�����������ˡ�\n" );
		else if( wc <= 30 ) write( "�������"+to_chinese(type)+"����������û���൱�����裬������\n"
								   "�������������ԣ�ֻ��һ������ʵ�ʵ����롣\n" );
		else if( wc <= 40 ) write( "��ʹ��һ������������Ϊ���սʿ���ܻ������һ���������������\n"
								   "��˵���ϱ��������ĸ�����\n" );
		else 				write( "����㲻����ʦ�Ļ������������������Ƿ�����������������ܻ��\n"
								   "�ģ�����µ��ƻ�������ֻ����ʦ���������ܺ����࿹�⡣\n" );
}

void identify_armor(object obj, int skill)
{
	int ac, db, value;
	string material;

	ac = (int)obj->query("armor_class");
	db = (int)obj->query("defense_bonus");
	switch( (string)obj->query("type") ) {
		case "head" : value = ac * 100 / 10;					break;
		case "body" : value = ac * 60 / 40 + db * 40 / 5;		break;
		case "arms" : value = ac * 80 / 5 +  db * 20 /5 ; 		break;
		case "hands" : value = ac * 80 / 5 +  db * 20 /5 ;		break;
		case "legs" : value = ac * 60 / 10 + db * 40/5 ;		break;
		case "feet" : value = ac * 100 / 10;	   	            break;
		case "shield" : value = ac * 100 / 10;					break;
		case "cloak" : value = ac * 100 / 10;					break;
		case "misc" : value = db * 100 / 10;					break;
		case "finger" : value = db * 100 / 10;					break;
		case "kernel" : value = ac * 40 / 10 + db * 60 / 20;	break;
		case "globe" : value = ac * 50 / 30 + db * 50 / 20;		break;
		case "saddle" : value = ac * 60 / 20 + db * 40 / 5;		break;
		case "tail" : value = ac * 100 / 10;					break;
	}
	if( value/2 + random(value/2) > skill )
		value = value/2 + random(value/2);
		switch ((string)obj->query("material")) {
			case "heavy_metal" :
				material = "�ؽ��������";
				break;
			case "light_metal" :
				material = "�������ɵ�";
				break;
			case "element" :
				material = "����Ԫ�����ɵ�";
				break;
			case "stone" :
				material = "Ӳ����ʯͷ��";
				break;
			case "wood" :
				material = "ľͷ����";
				break;
			case "leather" :
				material = "Ƥ�����Ƴɵ�";
				break;				
			case "cloth" :
				material = "������";
				break;
			default :
				material = "����ר�õ�";
				break;
		}
		if( value < 20 ) write( "��....����"+material+"����ֻ���ṩЩ��\�ı�����\n" );
		else if( value < 40 ) write( "��....���"+material+"���߿������ƺ�����̫�\n" );
		else if( value < 60 ) write( "��....���"+material+"���߿��������е����ϵ�Ʒ�ʡ�\n" );
		else if( value < 80 ) write( "��....���"+material+"���ߵ�Ʒ�ʼ��ߣ����ṩ���ܵı�����\n" );
		else write( "��....���"+material+"���������������ģ���������ѵġ�\n" );
}

int cmd_identify(string arg)
{
	int skill;
	object dest;


	if( this_player()->query("stop_attack") > 0 )
		return notify_fail( 
			"( �㻹û�������һ���������޷������κ���Ʒ�� )\n");

	if( !arg || arg=="" )
		return notify_fail( 
			"ָ���ʽ: itentify <��Ʒ��>\n");

	if( !dest= present( arg, this_player() ) )
		return notify_fail( 
			"��û������������\n");

	this_player()->block_attack(4); 

	skill = (int)this_player()->query_skill("identify");

	if( dest->query("weapon_class") ) 
		identify_weapon(dest, skill);
	else if( dest->query("armor_class") || dest->query("defense_bonus") ) 
		identify_armor(dest, skill);
	else write( 
		"��������Ȳ���������Ҳ���ǻ��ߡ�\n");

	return 1;
}

int help()
{
	write( @HELP
ʹ�ø�ʽ: identify <��Ʒ��>

�ж���Ʒ�ĺû�.
����������Ӱ�죬��������������.
HELP
	);
	return 1;
}
