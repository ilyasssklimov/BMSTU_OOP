#include "errors.h"
#include "action.h"
#include "figure.h"
#include "paint.h"


error do_action(data_to_draw &data, const int action)
{
    error rc = OK;
    static figure figure = init_figure();

    switch (action)
    {
    case DRAW:
        paint_figure(data, figure);
        break;

    case CREATE:
        // const char *filename = {"figure.txt"};
        rc = create_figure(figure, data.filename);
        break;

    case CARRYOVER:
        rc = carryover_figure(figure, data.coefficients);
        break;

    case SCALE:
        rc = scale_figure(figure, data.coefficients);
        break;

    case TURN:
        rc = turn_figure(figure, data.coefficients);
        break;

    case SAVE:
        // const char *filename_out = {"figure_out.txt"};
        rc = save_figure(figure, data.filename);
        break;

    case QUIT:
        free_figure(figure);
        break;

    default:
        rc = UNKNOWN;
    }

    // show_error(rc);
    return rc;
}
