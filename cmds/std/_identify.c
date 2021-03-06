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
		"这是一种" + to_chinese(type) + "。\n");

		if( wc <= 5 ) write( "与其说它是武器，不如说是件装饰品。\n" );
		else if( wc <= 10 ) write( "拿它当作武器，勉强可以凑和著使用。\n" );
		else if( wc <= 15 ) write( "它的品质看起来似乎值得花钱去买。\n" );
		else if( wc <= 20 ) write( "依你的经验，这样的武器算得上是高级品。\n" );
		else if( wc <= 25 ) write( "凭良心说，它可算得上是一般人心目中所谓的「神兵利器」了。\n" );
		else if( wc <= 30 ) write( "如果你在"+to_chinese(type)+"武器技能上没有相当的造诣，这样的\n"
								   "神兵利器对你而言，只是一个不切实际的梦想。\n" );
		else if( wc <= 40 ) write( "即使是一个毕生与武器为伍的战士，能获得这样一件完美的神兵利器\n"
								   "可说是上辈子修来的福气。\n" );
		else 				write( "如果你不是巫师的话，这样的武器可能是凡人在这个世界上所能获得\n"
								   "的，最可怕的破坏力量，只有巫师的神力方能和它相抗衡。\n" );
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
				material = "重金属打造的";
				break;
			case "light_metal" :
				material = "轻金属组成的";
				break;
			case "element" :
				material = "矿物元素做成的";
				break;
			case "stone" :
				material = "硬得像石头的";
				break;
			case "wood" :
				material = "木头钉的";
				break;
			case "leather" :
				material = "皮革硝制成的";
				break;				
			case "cloth" :
				material = "布做的";
				break;
			default :
				material = "公会专用的";
				break;
		}
		if( value < 20 ) write( "唉....这样"+material+"护具只能提供些许\的保护。\n" );
		else if( value < 40 ) write( "咦....这件"+material+"护具看起来似乎不算太差。\n" );
		else if( value < 60 ) write( "嗯....这件"+material+"护具看起来有中等以上的品质。\n" );
		else if( value < 80 ) write( "噢....这件"+material+"护具的品质极高，能提供严密的保护。\n" );
		else write( "哇....这件"+material+"护具是你所看过的，防护力最佳的。\n" );
}

int cmd_identify(string arg)
{
	int skill;
	object dest;


	if( this_player()->query("stop_attack") > 0 )
		return notify_fail( 
			"( 你还没有完成上一个动作，无法鉴定任何物品。 )\n");

	if( !arg || arg=="" )
		return notify_fail( 
			"指令格式: itentify <物品名>\n");

	if( !dest= present( arg, this_player() ) )
		return notify_fail( 
			"你没有这样东西。\n");

	this_player()->block_attack(4); 

	skill = (int)this_player()->query_skill("identify");

	if( dest->query("weapon_class") ) 
		identify_weapon(dest, skill);
	else if( dest->query("armor_class") || dest->query("defense_bonus") ) 
		identify_armor(dest, skill);
	else write( 
		"这件东西既不是武器，也不是护具。\n");

	return 1;
}

int help()
{
	write( @HELP
使用格式: identify <物品名>

判断物品的好坏.
受评估技能影响，鉴定结果会有误差.
HELP
	);
	return 1;
}
