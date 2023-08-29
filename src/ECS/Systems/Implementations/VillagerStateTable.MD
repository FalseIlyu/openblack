<table>
  <thead>
    <tr>
      <th>State</th>
      <th>Original Game State Callbacks</th>
    </tr>
  </thead>
<tbody>
<tr><td><code>INVALID_STATE</code></td><td><pre><code>	state 
</code></pre></td></tr>
<tr><td><code>MOVE_TO_POS</code></td><td><pre><code>	state 
	exitState 
	field0x50 
	field0x60 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>MOVE_TO_OBJECT</code></td><td><pre><code>	state 
	exitState 
	field0x50 
	field0x60 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>MOVE_ON_STRUCTURE</code></td><td><pre><code>	state 
	field0x50 
	field0x60 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>IN_SCRIPT</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
</code></pre></td></tr>
<tr><td><code>IN_DANCE</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x60 
</code></pre></td></tr>
<tr><td><code>FLEEING_FROM_OBJECT_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>LOOKING_AT_OBJECT_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>FOLLOWING_OBJECT_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>INSPECT_OBJECT_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>FLYING</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x60 
</code></pre></td></tr>
<tr><td><code>LANDED</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x60 
</code></pre></td></tr>
<tr><td><code>LOOK_AT_FLYING_OBJECT_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>SET_DYING</code></td><td><pre><code>	state 
	saveState 
	loadState 
</code></pre></td></tr>
<tr><td><code>DYING</code></td><td><pre><code>	state 
	saveState 
	loadState 
	field0x60 
</code></pre></td></tr>
<tr><td><code>DEAD</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x60 
</code></pre></td></tr>
<tr><td><code>DROWNING</code></td><td><pre><code>	state 
	entryState 
	exitState 
</code></pre></td></tr>
<tr><td><code>DOWNED</code></td><td><pre><code>	state 
</code></pre></td></tr>
<tr><td><code>BEING_EATEN</code></td><td><pre><code>	state 
	exitState 
</code></pre></td></tr>
<tr><td><code>GOTO_FOOD_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_FOOD_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>GOTO_WOOD_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_WOOD_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>WAIT_FOR_ANIMATION</code></td><td><pre><code>	state 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>IN_HAND</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
</code></pre></td></tr>
<tr><td><code>GOTO_PICKUP_BALL_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_PICKUP_BALL_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>MOVE_IN_FLOCK</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>MOVE_ALONG_PATH</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>MOVE_ON_PATH</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>FLEEING_AND_LOOKING_AT_OBJECT_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>GOTO_STORAGE_PIT_FOR_DROP_OFF</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_STORAGE_PIT_FOR_DROP_OFF</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>GOTO_STORAGE_PIT_FOR_FOOD</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_STORAGE_PIT_FOR_FOOD</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_HOME_WITH_FOOD</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>GO_HOME</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_HOME</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>AT_HOME</code></td><td><pre><code>	state 
	exitState 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_STORAGE_PIT_FOR_BUILDING_MATERIALS</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_BUILDING_SITE</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>BUILDING</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>GOTO_STORAGE_PIT_FOR_WORSHIP_SUPPLIES</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_STORAGE_PIT_FOR_WORSHIP_SUPPLIES</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>GOTO_WORSHIP_SITE_WITH_SUPPLIES</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>MOVE_TO_WORSHIP_SITE_WITH_SUPPLIES</code></td><td><pre><code>	state 
	exitState 
	field0x50 
	field0x60 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_WORSHIP_SITE_WITH_SUPPLIES</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>FORESTER_MOVE_TO_FOREST</code></td><td><pre><code>	state 
	exitState 
	field0x50 
	field0x60 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>FORESTER_GOTO_FOREST</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>FORESTER_ARRIVES_AT_FOREST</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>FORESTER_CHOPS_TREE</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>FORESTER_CHOPS_TREE_FOR_BUILDING</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>FORESTER_FINISHED_FORESTERING</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_BIG_FOREST</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_BIG_FOREST_FOR_BUILDING</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>FISHERMAN_ARRIVES_AT_FISHING</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>FISHING</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>WAIT_FOR_COUNTER</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>GOTO_WORSHIP_SITE_FOR_WORSHIP</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_WORSHIP_SITE_FOR_WORSHIP</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>WORSHIPPING_AT_WORSHIP_SITE</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>GOTO_ALTAR_FOR_REST</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_ALTAR_FOR_REST</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>AT_ALTAR_REST</code></td><td><pre><code>	state 
	field0x50 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>AT_ALTAR_FINISHED_REST</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>RESTART_WORSHIPPING_AT_WORSHIP_SITE</code></td><td><pre><code>	state 
	exitState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>RESTART_WORSHIPPING_CREATURE</code></td><td><pre><code>	state 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>FARMER_ARRIVES_AT_FARM</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>FARMER_PLANTS_CROP</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>FARMER_DIGS_UP_CROP</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>MOVE_TO_FOOTBALL_PITCH_CONSTRUCTION</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>FOOTBALL_WALK_TO_POSITION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>FOOTBALL_WAIT_FOR_KICK_OFF</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>FOOTBALL_ATTACKER</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>FOOTBALL_GOALIE</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>FOOTBALL_GOALIE</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>FOOTBALL_WON_GOAL</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>FOOTBALL_LOST_GOAL</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>START_MOVE_TO_PICK_UP_BALL_FOR_DEAD_BALL</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>ARRIVED_AT_PICK_UP_BALL_FOR_DEAD_BALL</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVED_AT_PUT_DOWN_BALL_FOR_DEAD_BALL_START</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVED_AT_PUT_DOWN_BALL_FOR_DEAD_BALL_END</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>FOOTBALL_MATCH_PAUSED</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>FOOTBALL_WATCH_MATCH</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>FOOTBALL_MEXICAN_WAVE</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CREATED</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_IN_ABODE_TO_TRADE</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_IN_ABODE_TO_PICK_UP_EXCESS</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>MAKE_SCARED_STIFF</code></td><td><pre><code>	state 
</code></pre></td></tr>
<tr><td><code>SCARED_STIFF</code></td><td><pre><code>	state 
</code></pre></td></tr>
<tr><td><code>WORSHIPPING_CREATURE</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>SHEPHERD_LOOK_FOR_FLOCK</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>SHEPHERD_MOVE_FLOCK_TO_WATER</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>SHEPHERD_MOVE_FLOCK_TO_FOOD</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>SHEPHERD_MOVE_FLOCK_BACK</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>SHEPHERD_DECIDE_WHAT_TO_DO_WITH_FLOCK</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>SHEPHERD_WAIT_FOR_FLOCK</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>SHEPHERD_SLAUGHTER_ANIMAL</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>SHEPHERD_FETCH_STRAY</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>SHEPHERD_GOTO_FLOCK</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>HOUSEWIFE_AT_HOME</code></td><td><pre><code>	state 
	exitState 
</code></pre></td></tr>
<tr><td><code>HOUSEWIFE_GOTO_STORAGE_PIT</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>HOUSEWIFE_ARRIVES_AT_STORAGE_PIT</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>HOUSEWIFE_PICKUP_FROM_STORAGE_PIT</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>HOUSEWIFE_RETURN_HOME_WITH_FOOD</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>HOUSEWIFE_MAKE_DINNER</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>HOUSEWIFE_SERVES_DINNER</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>HOUSEWIFE_CLEARS_AWAY_DINNER</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>HOUSEWIFE_DOES_HOUSEWORK</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>HOUSEWIFE_GOSSIPS_AROUND_STORAGE_PIT</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>HOUSEWIFE_STARTS_GIVING_BIRTH</code></td><td><pre><code>	state 
</code></pre></td></tr>
<tr><td><code>HOUSEWIFE_GIVING_BIRTH</code></td><td><pre><code>	state 
</code></pre></td></tr>
<tr><td><code>HOUSEWIFE_GIVEN_BIRTH</code></td><td><pre><code>	state 
</code></pre></td></tr>
<tr><td><code>CHILD_AT_CRECHE</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHILD_FOLLOWS_MOTHER</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHILD_BECOMES_ADULT</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>SITS_DOWN_TO_DINNER</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>EAT_FOOD</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>EAT_FOOD_AT_HOME</code></td><td><pre><code>	state 
	exitState 
</code></pre></td></tr>
<tr><td><code>GOTO_BED_AT_HOME</code></td><td><pre><code>	state 
	exitState 
</code></pre></td></tr>
<tr><td><code>SLEEPING_AT_HOME</code></td><td><pre><code>	state 
	exitState 
</code></pre></td></tr>
<tr><td><code>WAKE_UP_AT_HOME</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>START_HAVING_SEX</code></td><td><pre><code>	state 
	entryState 
	exitState 
	field0x50 
	validate
</code></pre></td></tr>
<tr><td><code>HAVING_SEX</code></td><td><pre><code>	state 
	entryState 
	exitState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>STOP_HAVING_SEX</code></td><td><pre><code>	state 
	entryState 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>START_HAVING_SEX_AT_HOME</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>HAVING_SEX_AT_HOME</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>STOP_HAVING_SEX_AT_HOME</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>WAIT_FOR_DINNER</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>HOMELESS_START</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>VAGRANT_START</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>MORN_DEATH</code></td><td><pre><code>	state 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>PERFORM_INSPECTION_REACTION</code></td><td><pre><code>	state 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>APPROACH_OBJECT_REACTION</code></td><td><pre><code>	state 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>INITIALISE_TELL_OTHERS_ABOUT_OBJECT</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>TELL_OTHERS_ABOUT_INTERESTING_OBJECT</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>APPROACH_VILLAGER_TO_TALK_TO</code></td><td><pre><code>	state 
	field0x50 
	field0x60 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>TELL_PARTICULAR_VILLAGER_ABOUT_OBJECT</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>INITIALISE_LOOK_AROUND_FOR_VILLAGER_TO_TELL</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>LOOK_AROUND_FOR_VILLAGER_TO_TELL</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>MOVE_TOWARDS_OBJECT_TO_LOOK_AT</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>INITIALISE_IMPRESSED_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>PERFORM_IMPRESSED_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>INITIALISE_FIGHT_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>PERFORM_FIGHT_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>HOMELESS_EAT_DINNER</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>INSPECT_CREATURE_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>PERFORM_INSPECT_CREATURE_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>APPROACH_CREATURE_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>INITIALISE_BEWILDERED_BY_MAGIC_TREE_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>PERFORM_BEWILDERED_BY_MAGIC_TREE_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>TURN_TO_FACE_MAGIC_TREE</code></td><td><pre><code>	state 
	exitState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>LOOK_AT_MAGIC_TREE</code></td><td><pre><code>	state 
	exitState 
	field0x50 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>DANCE_FOR_EDITING_PURPOSES</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>MOVE_TO_DANCE_POS</code></td><td><pre><code>	state 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>INITIALISE_RESPECT_CREATURE_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>PERFORM_RESPECT_CREATURE_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>FINISH_RESPECT_CREATURE_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>APPROACH_HAND_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>FLEEING_FROM_CREATURE_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>TURN_TO_FACE_CREATURE_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>WATCH_FLYING_OBJECT_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>POINT_AT_FLYING_OBJECT_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>DECIDE_WHAT_TO_DO</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>INTERACT_DECIDE_WHAT_TO_DO</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>EAT_OUTSIDE</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>RUN_AWAY_FROM_OBJECT_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>MOVE_TOWARDS_CREATURE_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>AMAZED_BY_MAGIC_SHIELD_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>VILLAGER_GOSSIPS</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHECK_INTERACT_WITH_ANIMAL</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHECK_INTERACT_WITH_WORSHIP_SITE</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHECK_INTERACT_WITH_ABODE</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHECK_INTERACT_WITH_FIELD</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHECK_INTERACT_WITH_FISH_FARM</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHECK_INTERACT_WITH_TREE</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHECK_INTERACT_WITH_BALL</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHECK_INTERACT_WITH_POT</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHECK_INTERACT_WITH_FOOTBALL</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHECK_INTERACT_WITH_VILLAGER</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHECK_INTERACT_WITH_MAGIC_LIVING</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>CHECK_INTERACT_WITH_ROCK</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_ROCK_FOR_WOOD</code></td><td><pre><code>	state 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>GOT_WOOD_FROM_ROCK</code></td><td><pre><code>	state 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>REENTER_BUILDING_STATE</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVE_AT_PUSH_OBJECT</code></td><td><pre><code>	state 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>TAKE_WOOD_FROM_TREE</code></td><td><pre><code>	state 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>TAKE_WOOD_FROM_POT</code></td><td><pre><code>	state 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>TAKE_WOOD_FROM_TREE_FOR_BUILDING</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>TAKE_WOOD_FROM_POT_FOR_BUILDING</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>SHEPHERD_TAKE_ANIMAL_FOR_SLAUGHTER</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>SHEPHERD_TAKES_CONTROL_OF_FLOCK</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>SHEPHERD_RELEASES_CONTROL_OF_FLOCK</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>DANCE_BUT_NOT_WORSHIP</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>FAINTING_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	validate 
</code></pre></td></tr>
<tr><td><code>START_CONFUSED_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	validate 
</code></pre></td></tr>
<tr><td><code>CONFUSED_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	validate 
</code></pre></td></tr>
<tr><td><code>AFTER_TAP_ON_ABODE</code></td><td><pre><code>	state 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>WEAK_ON_GROUND</code></td><td><pre><code>	state 
	exitState 
</code></pre></td></tr>
<tr><td><code>SCRIPT_WANDER_AROUND_POSITION</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
</code></pre></td></tr>
<tr><td><code>SCRIPT_PLAY_ANIM</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x60 
</code></pre></td></tr>
<tr><td><code>GO_TOWARDS_TELEPORT_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>TELEPORT_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>DANCE_WHILE_REACTING</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	validate 
</code></pre></td></tr>
<tr><td><code>CONTROLLED_BY_CREATURE</code></td><td><pre><code>	state 
	exitState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>POINT_AT_DEAD_PERSON</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	validate 
</code></pre></td></tr>
<tr><td><code>GO_TOWARDS_DEAD_PERSON</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	validate 
</code></pre></td></tr>
<tr><td><code>LOOK_AT_DEAD_PERSON</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	validate 
</code></pre></td></tr>
<tr><td><code>MOURN_DEAD_PERSON</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>NOTHING_TO_DO</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_WORKSHOP_FOR_DROP_OFF</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_STORAGE_PIT_FOR_WORKSHOP_MATERIALS</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>SHOW_POISONED</code></td><td><pre><code>	state 
</code></pre></td></tr>
<tr><td><code>HIDING_AT_WORSHIP_SITE</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
</code></pre></td></tr>
<tr><td><code>CROWD_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>REACT_TO_FIRE</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	validate 
</code></pre></td></tr>
<tr><td><code>PUT_OUT_FIRE_BY_BEATING</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	validate 
</code></pre></td></tr>
<tr><td><code>PUT_OUT_FIRE_WITH_WATER</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	validate 
</code></pre></td></tr>
<tr><td><code>GET_WATER_TO_PUT_OUT_FIRE</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	validate 
</code></pre></td></tr>
<tr><td><code>ON_FIRE</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
</code></pre></td></tr>
<tr><td><code>MOVE_AROUND_FIRE</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>DISCIPLE_NOTHING_TO_DO</code></td><td><pre><code>	state 
	entryState 
	saveState 
	loadState 
	field0x50 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>FOOTBALL_MOVE_TO_BALL</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_STORAGE_PIT_FOR_TRADER_PICK_UP</code></td><td><pre><code>	state 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_STORAGE_PIT_FOR_TRADER_DROP_OFF</code></td><td><pre><code>	state 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>BREEDER_DISCIPLE</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate
</code></pre></td></tr>
<tr><td><code>MISSIONARY_DISCIPLE</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>REACT_TO_BREEDER</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>SHEPHERD_CHECK_ANIMAL_FOR_SLAUGHTER</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>INTERACT_DECIDE_WHAT_TO_DO_FOR_OTHER_VILLAGER</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARTIFACT_DANCE</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>FLEEING_FROM_PREDATOR_REACTION</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
	transitionAnimation 
	validate 
</code></pre></td></tr>
<tr><td><code>WAIT_FOR_WOOD</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>INSPECT_OBJECT</code></td><td><pre><code>	state 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>GO_HOME_AND_CHANGE</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>WAIT_FOR_MATE</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>GO_AND_HIDE_IN_NEARBY_BUILDING</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>LOOK_TO_SEE_IF_IT_IS_SAFE</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>SLEEP_IN_TENT</code></td><td><pre><code>	state 
	field0x50 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>PAUSE_FOR_A_SECOND</code></td><td><pre><code>	state 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>PANIC_REACTION</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
<tr><td><code>GET_FOOD_AT_WORSHIP_SITE</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>GOTO_CONGREGATE_IN_TOWN_AFTER_EMERGENCY</code></td><td><pre><code>	state 
</code></pre></td></tr>
<tr><td><code>CONGREGATE_IN_TOWN_AFTER_EMERGENCY</code></td><td><pre><code>	state 
	field0x60 
</code></pre></td></tr>
<tr><td><code>SCRIPT_IN_CROWD</code></td><td><pre><code>	state 
	saveState 
	loadState 
	field0x60 
</code></pre></td></tr>
<tr><td><code>GO_AND_CHILLOUT_OUTSIDE_HOME</code></td><td><pre><code>	state 
</code></pre></td></tr>
<tr><td><code>SIT_AND_CHILLOUT</code></td><td><pre><code>	state 
	entryState 
	field0x60 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>SCRIPT_GO_AND_MOVE_ALONG_PATH</code></td><td><pre><code>	state 
	entryState 
	exitState 
</code></pre></td></tr>
<tr><td><code>RESTART_MEETING</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>GOTO_ABODE_BURNING_REACTION</code></td><td><pre><code>	state 
	exitState 
	field0x50 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_ABODE_BURNING_REACTION</code></td><td><pre><code>	state 
	field0x50 
	transitionAnimation 
</code></pre></td></tr>
<tr><td><code>REPAIRS_ABODE</code></td><td><pre><code>	state 
	exitState 
	saveState 
	loadState 
	field0x50 
	validate 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_SCAFFOLD_FOR_PICKUP</code></td><td><pre><code>	state 
</code></pre></td></tr>
<tr><td><code>ARRIVES_AT_BUILDING_SITE_WITH_SCAFFOLD</code></td><td><pre><code>	state 
	entryState 
	exitState 
	saveState 
	loadState 
	field0x50 
	field0x60 
</code></pre></td></tr>
<tr><td><code>MOVE_SCAFFOLD_TO_BUILDING_SITE</code></td><td><pre><code>	state 
	field0x50 
</code></pre></td></tr>
  </tbody>
</table>
