from sys import argv
import sys


def parse_state_information(filename):
    """
    filename: str -> state_info: dict
    Opens the state information file named in filename, loads all of the 
    values, placing them in a single data structure. Returns that data 
    structure.  You may created nested data structures.

    The state_info is structured as: {state_name: [population, electoral_votes]}
    """
    result = {}
    with open(filename, "r") as f:
        for line in f.readlines():
            lst_tmp = line.split(":")
            if len(lst_tmp)!=3:
                continue
            result.update({lst_tmp[0]: [int(lst_tmp[1]), int(lst_tmp[2].strip())]})
    return result
    

def print_state_information(state_info):
    """
    state_info: dict -> None
    For the state_info data structure (produced as a result),  
    print all statues in alphabetical order using the string:
    "{}: Population - {:,d}, Electoral Votes: {:d}"

    """
    for i in state_info.keys():
        print(f"{i}: Population - {state_info.get(i)[0]:,d}, Electoral Votes: {state_info.get(i)[1]:d}")
    return


def parse_vote_information(filename):
    """
    filename: str -> vote_info: dict
    Opens the vote information file and returns the information 
    in a data structure
    The vote_info is structured as: {state: votes}
    """
    result = {}
    with open(filename, "r") as f:
        for line in f.readlines():
            lst_tmp = line.split(":")
            if len(lst_tmp)!=2:
                continue
            result.update({lst_tmp[0]: int(lst_tmp[1].strip())})
    return result


def count_electoral_votes(state_info, vote_info):
    """
    state_info: dict, vote_info: dict -> electoral_count: int
    Counts and returns the number of electoral votes received by 
    Candidate A in the election.

    For our purposes, Candidate A receives ALL electoral votes for a
    state if Candidate A receives strictly more than 50% of the votes in
    that State.  [Yes, we know that in the US there are a few states
    with more complex rules, but we will ignore them.  We will also
    ignore the electoral complexities of what would happen if a
    candidate received exactly 50%, and in this case, just say that
    Candidate A does not receive those electoral votes.  We are also
    assuming everyone in every state votes--while this doesn't happen in
    a real election, it is what we are doing here].
    """
    state_population = {}
    state_electoral = {}
    for key in state_info.keys():
        state_population.update({key: state_info.get(key)[0]})
        state_electoral.update({key: state_info.get(key)[1]})
    vote_result = {}
    # calculate the proportion of votes and compare it with 50%
    for key in vote_info.keys():
        vote_result.update({key: ((vote_info.get(key)/state_population.get(key))>0.5)})
    # count electoral votes
    electoral_count = 0
    for key in vote_result.keys():
        if vote_result.get(key):
            electoral_count += state_electoral.get(key)
    return electoral_count


def determine_winner(state_info, candidate_a_electoral_votes):
    """
    state_info: dict, candidate_a_electoral_votes: dict -> winner: str
    Determines whether Candidate A or Candidate B won based upon who
    won the majority of the electoral votes. If there is a tie, return None.
    Returns "A", "B", or None    the last one is the value None
    """
    total_electoral_votes = 0
    for i in state_info.values():
        total_electoral_votes += i[1]
    A_votes = candidate_a_electoral_votes
    B_votes = total_electoral_votes - A_votes
    if (A_votes==B_votes):
        return None
    elif (A_votes>B_votes):
        return "A"
    else:
        return "B"


def determine_winnner_votes(state_info, candidate_a_electoral_votes):
    """
    state_info: dict, candidate_a_electoral_votes: dict -> winner_votes: int
    Determines whether Candidate A or Candidate B won based upon who
    won the majority of the electoral votes. If there is a tie, return None.
    Returns "A", "B", or None    the last one is the value None
    """
    total_electoral_votes = 0
    for i in state_info.values():
        total_electoral_votes += i[1]
    A_votes = candidate_a_electoral_votes
    B_votes = total_electoral_votes - A_votes
    if (A_votes==B_votes):
        return None
    elif (A_votes>B_votes):
        return A_votes
    else:
        return B_votes
    

def print_winner(winner_name, number_of_votes):
    """
    winner_name: str, number_of_votes: int -> None
    Prints the winner.  If Candidate A or B wins, print
    "Candidate {} wins the election with {:d} votes" using the winner_name
    and number of Electoral College votes.

    If neither won the vote, print "It's a tie in the Electoral College."
    """
    if winner_name is None:
        print("It's a tie in the Electoral College.")
    print(f"Candidate {winner_name} wins the election with {number_of_votes:d} votes")


def determine_recounts(state_info, vote_info):
    """
    Produces a list of strings, where each string represents information
    about a state the requires a recount. Recounts are required when a 
    Candidate A is within +/ 0.5% of 50% of the votes.  So 49.50% or 50.50%
    require a recount, while 49.49% and 50.51% do not require a recount.
    
    Only include states that require a recount in the result. For each state
    that requires a recount, include a line of the form:
    "{} requires a recount (Candidate A has {:.2f}% of the vote)".
    """
    state_population = {}
    state_electoral = {}
    for key in state_info.keys():
        state_population.update({key: state_info.get(key)[0]})
        state_electoral.update({key: state_info.get(key)[1]})
    # calculate the proportion of votes and compare it with 50%
    recount_result = []
    for key in vote_info.keys():
        votes=(vote_info.get(key)/state_population.get(key))
        if votes<0.505 and votes>0.495:
            line=f'''
                {key} requires a recount (Candidate A has {(votes)*100:.2f}% of the vote)
            '''
            recount_result.append(line.strip()+"\n")
    return recount_result


def save_recounts(recount_list):
    """
    saves each entry of the list to a file named "recounts.txt".  The
    entries must be printed in alphabetical order.
    """
    with open("recounts.txt", 'w') as f:
        f.writelines(recount_list)


def determine_largest_win(state_info, vote_info):
    """
    state_info: dict, vote_info: dict -> 
    Determines in which state Candidate A won the largest percentage 
    of the vote.

    returns a string with the following format:
    "Candidate A won {} with {:.2f}% of the vote"

    where the first {} should be the name of the state, and the {.2f} 
    should be the percentage of the vote won.  For example, it might return
    "Candidate A won California with 73.24% of the vote"

    None is returned if candidate A did not win a state
    """
    state_population = {}
    state_electoral = {}
    for key in state_info.keys():
        state_population.update({key: state_info.get(key)[0]})
        state_electoral.update({key: state_info.get(key)[1]})
    vote_result = {}
    # calculate the proportion of votes and compare it with 50%
    for key in vote_info.keys():
        vote_result.update({key: (vote_info.get(key)/state_population.get(key))})
    vote_rank = sorted(vote_result, key=vote_result.get, reverse=True)
    return f"Candidate A won {vote_rank[0]} with {vote_result.get(vote_rank[0])*100:.2f}% of the vote"
    

def process(state_info_filename, vote_info_filename):
    """
    Implements the "Several steps exist for this assignment" section
    """
    state_info = parse_state_information(state_info_filename)
    print_state_information(state_info)
    vote_info = parse_vote_information(vote_info_filename)
    candidate_a_electoral_votes = count_electoral_votes(state_info, vote_info)
    winner = determine_winner(state_info, candidate_a_electoral_votes)
    winner_votes = determine_winnner_votes(state_info, candidate_a_electoral_votes)
    print_winner(winner, winner_votes)
    recount_list = determine_recounts(state_info, vote_info)
    save_recounts(recount_list)
    print(determine_largest_win(state_info, vote_info))


if __name__ == "__main__":
    """implement checking command line arguments, call process()"""
    if len(argv) != 3:
        print("Usage: python3 election.py state_info_filename voter_info_filename")
        sys.exit(101)
    
    state_info_filename = argv[1]
    vote_info_filename = argv[2]
    process(state_info_filename, vote_info_filename)